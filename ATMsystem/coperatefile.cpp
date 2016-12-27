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
	//��ָ���û���Ϣ��ָ�벻Ϊ��ʱ����ʱ��Ҫ������һ���û�������Ҫ�ͷ�ǰһ���û����ڴ�
	while(customerinfo){
		ccustomerinfodata *pcustomerinfo=NULL;
		pcustomerinfo=customerinfo->pnext;
		delete customerinfo->user;
		delete customerinfo;
		customerinfo=pcustomerinfo;
	}
	//ͬ��ɾ���˻���Ϣ
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
		cout<<"���ܴ��ļ�"<<endl;
		return;
	}
	while(!fin.eof()){
	fin>>struseraccount>>strusername>>struserphone>>struseradress>>struserpassword>>strcardid;
		if(fin.fail()){
			return;
		}
		long int nuseraccount=atoi(struseraccount.c_str());
		ccustomerinfodata *ptailuserinfodata=new ccustomerinfodata;
		ptailuserinfodata->user=new ccustomerinfo(nuseraccount,strusername,struserphone,struseradress,struserpassword,strcardid);//��ʱ�����ָ��ʹ��new
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
//���ļ������ݶ�����Ӧ�û������У�������ҳ����ʾ����
void coperatefile::readaccountinfo(){
	int i=0;
	string straccountnum,straccpassword,straccbalance,strflag;
	fstream fin;
	fin.open("account.txt");
	caccountinfodata *pcurrentaccinfodata=NULL;
	if(!fin.is_open()){
		cout<<"�ļ��򿪴���"<<endl;
		return;
	}
	//�ļ�������ʱ����whileѭ�������Ƿ񵽴��ļ�ĩβ,.eof()��
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
//������д�뵽�ļ��У�Ҳ������ζ�Ž����ݴ��뵽���ݿ���
void coperatefile::saveuserinfo(){
	ofstream fout;
	fout.open("user.txt",ofstream::app);
	if(!fout.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	ccustomerinfodata *pcustomerinfo=NULL;
	pcustomerinfo=customerinfo;
	//�����ļ�д�뵽���ݿ�ʱ����ʱ����û���ļ�Ϊ����
	while(pcustomerinfo){//���ļ���д����ʱ��Ӧ��ʹ��public���ֵĺ�����д�����ܷ���˽������
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
		cout<<"�ļ��򿪲���ȷ"<<endl;
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
		cout<<"���ܴ��ļ�"<<endl;
		return;
	}
	while(!fin.eof()){
	fin>>struseraccount>>strusername>>struserphone>>struseradress>>struserpassword>>strcardid;
		if(fin.fail()){
			return;
		}
		long int nuseraccount=atoi(struseraccount.c_str());
		ccustomerinfodata *ptailuserinfodata=new ccustomerinfodata;
		ptailuserinfodata->user=new ccustomerinfo(nuseraccount,strusername,struserphone,struseradress,struserpassword,strcardid);//��ʱ�����ָ��ʹ��new
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
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	//һ��Ὣԭ�������Ա��������һ��ָ�룬��Ҫֱ�Ӳ������Ա
	ccustomerinfodata *pcustomerinfo=NULL;
	pcustomerinfo=customerinfo;
	//�����ļ�д�뵽���ݿ�ʱ����ʱ����û���ļ�Ϊ����
	while(pcustomerinfo){//���ļ���д����ʱ��Ӧ��ʹ��public���ֵĺ�����д�����ܷ���˽������
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











