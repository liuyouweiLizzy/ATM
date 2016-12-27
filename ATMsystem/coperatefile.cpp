#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"coperatefile.h"
#include"ccustomer.h"
#include"caccountinfo.h"
#include"form.h"
using namespace std;
coperatefile::coperatefile(){
	customerinfo=NULL;
	accountinfo=NULL;
}
coperatefile::~coperatefile(){
	//当指向用户信息的指针不为空时，这时想要访问下一个用户，则需要释放前一个用户的内存
	while(customerinfo){
		ccustomerinfodata *pcustomerinfo=NULL;
		pcustomerinfo=customerinfo->pnext;
		delete customerinfo->user;
		delete customerinfo;
		customerinfo=pcustomerinfo;
	}
	//同理，删除账户信息
	while(accountinfo){
		caccountinfodata *paccountinfo=NULL;
		paccountinfo=accountinfo->pnext;
		delete accountinfo->account;
		delete accountinfo;
		accountinfo=paccountinfo;
	}
}
void coperatefile::readuserinfo(){
	int i=0;
	string struseraccount,strusername,struserphone,struseradress,struserpassword,
		strcardid;
	ccustomerinfodata *pcurrentuserinfodata=NULL;
	ifstream fin;
	fin.open("user.txt");
	if(!fin.is_open()){
		cout<<"不能打开文件"<<endl;
		return;
	}
	while(!fin.eof()){
	fin>>struseraccount>>strusername>>struserphone>>struseradress>>struserpassword>>strcardid;
		if(fin.fail()){
			return;
		}
		long int nuseraccount=atoi(struseraccount.c_str());
		ccustomerinfodata *ptailuserinfodata=new ccustomerinfodata;
		ptailuserinfodata->user=new ccustomerinfo(nuseraccount,strusername,struserphone,struseradress,struserpassword,strcardid);//临时分配的指针使用new
		if(i==0){
			customerinfo=pcurrentuserinfodata=ptailuserinfodata;
			++i;
		}
		else{
			pcurrentuserinfodata->pnext=ptailuserinfodata;
			pcurrentuserinfodata=ptailuserinfodata;
		}
		ptailuserinfodata->pnext=NULL;
	}
	return;

}
//将文件的内容读到相应用户变量中，用于在页面显示出来
void coperatefile::readaccountinfo(){
	int i=0;
	string straccountnum,straccpassword,straccbalance,strflag;
	fstream fin;
	fin.open("account.txt");
	caccountinfodata *pcurrentaccinfodata=NULL;
	if(!fin.is_open()){
		cout<<"文件打开错误"<<endl;
		return;
	}
	//文件读出的时候，以while循环看其是否到达文件末尾,.eof()。
	while(!fin.eof()){
		fin>>straccountnum>>straccpassword>>straccbalance>>strflag;
		long int naccountnum=atoi(straccountnum.c_str());
		int nflag=atoi(strflag.c_str());
		if(fin.fail()){
			return;
		}
		caccountinfodata *ptailaccinfodata=new caccountinfodata;
		ptailaccinfodata->account=new caccountinfo(naccountnum,straccpassword,straccbalance,nflag);
		if(i==0){
			accountinfo=pcurrentaccinfodata=ptailaccinfodata;
			++i;
		}
		else{
			pcurrentaccinfodata->pnext=ptailaccinfodata;
			pcurrentaccinfodata=ptailaccinfodata;
		}
		ptailaccinfodata->pnext=NULL;
	}
	return;
}
//将数据写入到文件中，也就是意味着将数据存入到数据库中
void coperatefile::saveuserinfo(){
	ofstream fout;
	fout.open("user.txt",ofstream::app);
	if(!fout.is_open()){
		cout<<"文件打开失败"<<endl;
		return;
	}
	ccustomerinfodata *pcustomerinfo=NULL;
	pcustomerinfo=customerinfo;
	//当将文件写入到数据库时，这时以有没有文件为条件
	while(pcustomerinfo){//向文件中写内容时，应该使用public部分的函数来写，不能访问私有内容
		fout<<pcustomerinfo->user->getuseraccount()<<endl;
        fout<<pcustomerinfo->user->getusername()<<endl;
		fout<<pcustomerinfo->user->getuserphone()<<endl;
		fout<<pcustomerinfo->user->getuseradress()<<endl;
		fout<<pcustomerinfo->user->getuserpassword()<<endl;
		fout<<pcustomerinfo->user->getcardid()<<endl;
		pcustomerinfo=pcustomerinfo->pnext;
	}
	fout.close();
	return;
}
void coperatefile::saveaccountinfo(){
	ofstream fout;
	fout.open("account.txt");
	if(!fout.is_open()){
		cout<<"文件打开不正确"<<endl;
		return;
	}
	caccountinfodata *paccountinfo=NULL;
	paccountinfo=accountinfo;
	while(paccountinfo){
		fout<<paccountinfo->account->getaccountNum()<<endl;
		fout<<paccountinfo->account->getpassword()<<endl;
		fout<<paccountinfo->account->getbalance()<<endl;
		fout<<paccountinfo->account->getflag()<<endl;
		paccountinfo=paccountinfo->pnext;
	}
	fout.close();
	return;
}
long int coperatefile::findmaxcardid(){
	long int nmaxnum=0;
	ccustomerinfodata *puserinfo=NULL;
	puserinfo=customerinfo;
	while(puserinfo){
		if(puserinfo->user->getuseraccount()>=nmaxnum){
			nmaxnum=puserinfo->user->getuseraccount();
		}
		puserinfo=puserinfo->pnext;
	}
	return nmaxnum;
}
void coperatefile::readuserinfo(char *pname){
	int i=0;
	string struseraccount,strusername,struserphone,struseradress,struserpassword,
		strcardid;
	ccustomerinfodata *pcurrentuserinfodata=NULL;
	ifstream fin;
	fin.open(pname);
	if(!fin.is_open()){
		cout<<"不能打开文件"<<endl;
		return;
	}
	while(!fin.eof()){
	fin>>struseraccount>>strusername>>struserphone>>struseradress>>struserpassword>>strcardid;
		if(fin.fail()){
			return;
		}
		long int nuseraccount=atoi(struseraccount.c_str());
		ccustomerinfodata *ptailuserinfodata=new ccustomerinfodata;
		ptailuserinfodata->user=new ccustomerinfo(nuseraccount,strusername,struserphone,struseradress,struserpassword,strcardid);//临时分配的指针使用new
		if(i==0){
			customerinfo=pcurrentuserinfodata=ptailuserinfodata;
			++i;
		}
		else{
			pcurrentuserinfodata->pnext=ptailuserinfodata;
			pcurrentuserinfodata=ptailuserinfodata;
		}
		ptailuserinfodata->pnext=NULL;
	}
	return;

}
void coperatefile::saveuserinfo(char *pname){
		ofstream fout;
	fout.open(pname,ofstream::app);
	if(!fout.is_open()){
		cout<<"文件打开失败"<<endl;
		return;
	}
	//一般会将原来的类成员拷贝给另一个指针，不要直接操作类成员
	ccustomerinfodata *pcustomerinfo=NULL;
	pcustomerinfo=customerinfo;
	//当将文件写入到数据库时，这时以有没有文件为条件
	while(pcustomerinfo){//向文件中写内容时，应该使用public部分的函数来写，不能访问私有内容
		fout<<pcustomerinfo->user->getuseraccount()<<endl;
		fout<<pcustomerinfo->user->getusername()<<endl;
		fout<<pcustomerinfo->user->getuserphone()<<endl;
		fout<<pcustomerinfo->user->getuseradress()<<endl;
		fout<<pcustomerinfo->user->getuserpassword()<<endl;
		fout<<pcustomerinfo->user->getcardid()<<endl;
		pcustomerinfo=pcustomerinfo->pnext;
	}
	fout.close();
	return;
}











