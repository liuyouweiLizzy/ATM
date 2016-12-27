#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<sstream>
#include"coperatefile.h"
#include"ccustomer.h"
#include"form.h"
#include"caccountinfo.h"
#include"ctransaction.h"
using namespace std;
ctransaction::ctransaction(long int num):useraccount(num){}
ctransaction::~ctransaction(){}
void ctransaction::openaccount(){
	long int nuseraccount=0;
	ofstream fout1,fout2;
	fout1.open("user.txt",ofstream::app);
	fout2.open("account.txt",ofstream::app);
	string strusername,struserphone,struseradress,struserpassword,strcardid;
	string strdecision;
	cout<<"请输入姓名:";
	cin>>strusername;
	cout<<"请输入身份证号:";
	cin>>strcardid;
	cout<<"请输入密码:";
	cin>>struserpassword;
	cout<<"请输入电话号码:";
	cin>>struserphone;
	cout<<"请输入住址:";
	cin>>struseradress;
	system("cls");
	cmainform mainform;
	mainform.DisplyOpenDefine();
	cout<<"您输入的信息为:"<<endl;
	cout<<"姓名:"<<strusername<<"\n"<<"身份证号:"<<strcardid<<"\n"<<"密码:"<<struserpassword<<"\n"<<"电话号码:"<<struserphone<<"\n"<<"住址:"<<struseradress<<endl;
	coperatefile p;
	p.readuserinfo();
	nuseraccount=p.findmaxcardid()+1;
	cout<<"生成账户为:"<<nuseraccount<<"\n"<<"请确定是否开户(Y/N)"<<endl;
	while(1){
		cin>>strdecision;
		if(strdecision=="Y"||strdecision=="y"){
			fout1<<nuseraccount<<endl;
			fout1<<strusername<<endl;
			fout1<<struserphone<<endl;
			fout1<<struserpassword<<endl;
			fout1<<strcardid<<endl;
			fout2<<nuseraccount<<endl;
			fout2<<struserpassword<<endl;
			fout2<<"10"<<endl;
			fout2<<"1"<<endl;
			fout1.close();
			fout2.close();
			cout<<"开户完成，请按任意键结束"<<endl;
			getch();
			break;
		}
		else if(strdecision=="N"||strdecision=="n"){
			fout1.close();
			fout2.close();
			break;
		}
		else{
			cout<<"您输入的不正确"<<endl;
		}
	}
	return;
}
void ctransaction::deleteaccount(){
	int i=0;
	string strinput;
	cout<<"请输入账号:";
	cin>>strinput;
	long int ninputnum=atoi(strinput.c_str());
	coperatefile p;
	p.readaccountinfo();
	caccountinfodata *paccountinfodata=NULL;
	paccountinfodata=p.accountinfo;
	while(paccountinfodata){
		if(paccountinfodata->account->getaccountNum()==ninputnum){
			paccountinfodata->account->setbalance("0");
			paccountinfodata->account->setflag(0);
			++i;
			break;
		}
		else{
			paccountinfodata=paccountinfodata->pnext;
		}
	}
	if(i==1){
		cout<<"销户成功,按任意键返回"<<endl;
		p.saveaccountinfo();
		getch();
	}
	else{
		cout<<"销户失败，请检查账号是否正确，按任意键返回...."<<endl;
		getch();
	}
	return;
}
void ctransaction::leadincustomer(){
	string filename1;
	string filename2;
	filename1="user.txt";
	cout<<"请输入需要导入的文件名:";
	cin>>filename2;
	coperatefile p;
	ifstream fin;
	fin.open(&filename2[0]);
	if(!fin.is_open()){
		cout<<"文件无法读取，请查证后重新输入，按任意键返回..."<<endl;
		getch();
	}
	else{
		p.readuserinfo(&filename2[0]);
		p.saveuserinfo(&filename1[0]);
		ccustomerinfodata *pcustomerinfo=NULL;
		pcustomerinfo=p.customerinfo;
		ofstream fout;
		fout.open("account.txt",ofstream::app);
		while(pcustomerinfo){
			fout<<pcustomerinfo->user->getuseraccount()<<endl;
			fout<<pcustomerinfo->user->getuserpassword()<<endl;
			fout<<"10"<<endl;
			fout<<"1"<<endl;
			pcustomerinfo=pcustomerinfo->pnext;
		}
		fout.close();
		cout<<"导入完毕,按任意键返回"<<endl;
		getch();
	}
	fin.close();
	return;
}
void ctransaction::leadoutcustomer(){
	coperatefile p;
	ofstream fout;
	ifstream fin;
	string filename,strusername;
	cout<<"请输入用户名:";
	cin>>strusername;
	filename="content.txt";
	fin.open("user.txt");
	if(!fin.is_open()){
		cout<<"有问题，按任意键返回"<<endl;
		getch();
	}
	else{
		fin.close();
		p.readuserinfo();
		p.saveuserinfo(&filename[0]);
		cout<<"导出成功，按任意键返回"<<endl;
		getch();
	}
	return;
}
void ctransaction::deposite(){
	string strinmoney;
	int i=0;
	long int accountnum;
	coperatefile p;
	ostringstream fomated;
	cout<<"请输入存入账号:";
	cin>>accountnum;
	cout<<"请输入存款金额:";
	cin>>strinmoney;
	long int numbalance;
	p.readaccountinfo();
	caccountinfodata *paccountinfo=NULL;
	paccountinfo=p.accountinfo;
	while(paccountinfo){
		if(paccountinfo->account->getaccountNum()==accountnum){
			numbalance=atoi(paccountinfo->account->getbalance().c_str())+atoi(strinmoney.c_str());
			fomated<<" "<<numbalance;
			paccountinfo->account->setbalance(fomated.str());
			++i;
			break;
		}
		else{
			paccountinfo=paccountinfo->pnext;
		}
	}
	if(i==1){
		p.saveaccountinfo();
		cout<<"存款成功，按任意键返回..."<<endl;
		getch();
	}
	else{
		cout<<"找不到该账号，按任意键返回..."<<endl;
		getch();
	}
	return;
}
void ctransaction::withdraw(){
	int i=1,n=0;
	coperatefile p;
	ostringstream fomated;
	long int naccountnum;
	long int ndrawmoney,ntype,nmoney;
	cout<<"请输入账号:";
	cin>>naccountnum;
	cout<<"1.100  2.200  3.500  4.1000  5.其它"<<endl;
	cout<<"请输入取款金额:";
	cin>>ntype;
	while(1){
		if(ntype>5||ntype<1){
			cout<<"输入错误，请重新输入..."<<endl;
			ntype=0;
			cin>>ntype;
			++i;
			if(i==4){
				break;
			}
		}
		else{
			break;
		}
	}
	if(i==4){
		cout<<"您输入错误次数超过三次，不予办理业务..."<<endl;
		return;
	}
	p.readaccountinfo();
	caccountinfodata *paccountinfo;
	paccountinfo=p.accountinfo;
	while(paccountinfo){
		if(paccountinfo->account->getaccountNum()==naccountnum){
			switch(ntype){
			case 1:
				if(100>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"余额不足"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-100;
					break;
				}
			case 2:
				if(200>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"余额不足"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-200;
					return;
				}
			case 3:
					if(500>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"余额不足"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-500;
					break;
				}
			case 4:
					if(1000>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"余额不足"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-1000;
					break;
				}
			case 5:
				cout<<"请输入取款金额数:";
				cin>>ndrawmoney;
				if(ndrawmoney>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"余额不足"<<endl;
					return;
				}
				else if(ndrawmoney%100!=0||ndrawmoney>=2500){
					cout<<"输入金额错误!"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-ndrawmoney;
					break;
				}
			}
			fomated<<" "<<nmoney;
			paccountinfo->account->setbalance(fomated.str());
			++n;
		}
		else{
			paccountinfo=paccountinfo->pnext;
		}
	}
	if(n==1){
		p.saveaccountinfo();
		cout<<"请取走您的现金，按任意键退出..."<<endl;
		getch();
	}
	else{
		cout<<"找不到该账号，请查证后重新输入..."<<endl;
		return;
	}
	return;
}
void ctransaction::tranfer(){
	ostringstream fomated1,fomated2;
	int ntype=0;
	coperatefile p;
	caccountinfodata *paccountinfo1=NULL;
	caccountinfodata *paccountinfo2=NULL;
	long int accountnum1,accountnum2;
	long int ntransmoney;
	long int nmoney1,nmoney2;
	cout<<"请输入转出账户号:";
	cin>>accountnum1;
	cout<<"请输入转入账户号:";
	cin>>accountnum2;
	cout<<"请输入转账金额:";
	cin>>ntransmoney;
	if(accountnum1==accountnum2){
		cout<<"输入错误,任意键返回"<<endl;
		getch();
		return;
	}
	p.readaccountinfo();
	paccountinfo1=p.accountinfo;
	paccountinfo2=p.accountinfo;
	while(paccountinfo2){
		if(paccountinfo2->account->getaccountNum()==accountnum2&&paccountinfo2->account->getflag()!=0){
			ntype=1;
			break;
		}
		else{
			paccountinfo2=paccountinfo2->pnext;
		}
	}
	if(!ntype){
		cout<<"账户无效，请查证后重新输入，按任意键返回..."<<endl;
		getch();
		return;
	}
	while(paccountinfo1){
		if(paccountinfo1->account->getaccountNum()==accountnum1){
			while(paccountinfo2){
				if(paccountinfo2->account->getaccountNum()==accountnum2){
					if(ntransmoney<=atoi((paccountinfo1->account->getbalance()).c_str())){
						nmoney1=atoi((paccountinfo1->account->getbalance()).c_str())-ntransmoney;
						nmoney2=atoi((paccountinfo2->account->getbalance()).c_str())+ntransmoney;
						break;
					}
					else{
						cout<<"余额不足!"<<endl;
						return;
					}
				}
				else{
					paccountinfo2=paccountinfo2->pnext;
				}
			}
			fomated1<<" "<<nmoney1;
			fomated2<<" "<<nmoney2;
			paccountinfo1->account->setbalance(fomated1.str());
			paccountinfo2->account->setbalance(fomated2.str());
			break;
		}
		else{
			paccountinfo1=paccountinfo1->pnext;
		}
	}
	p.saveaccountinfo();
	cout<<"转账成功"<<endl;
	return;
}
void ctransaction::checkbalance(){
	coperatefile p;
	int i=0;
	long int naccountnum;
	string strbalance;
	cout<<"请输入账户:"<<endl;
	cin>>naccountnum;
	p.readaccountinfo();
	caccountinfodata *paccountinfo;
	paccountinfo=p.accountinfo;
	while(paccountinfo){
		if(paccountinfo->account->getaccountNum()==naccountnum){
			strbalance=paccountinfo->account->getbalance();
			++i;
			break;
		}
		else{
			paccountinfo=paccountinfo->pnext;
		}
	}
	if(i==1){
		cout<<"账户余额为:"<<strbalance<<"元"<<endl;
	}
	else{
		cout<<"账户不存在，按任意键退出!"<<endl;
		getch();
		return;
	}
	return;
}























