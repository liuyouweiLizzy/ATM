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
	cout<<"����������:";
	cin>>strusername;
	cout<<"���������֤��:";
	cin>>strcardid;
	cout<<"����������:";
	cin>>struserpassword;
	cout<<"������绰����:";
	cin>>struserphone;
	cout<<"������סַ:";
	cin>>struseradress;
	system("cls");
	cmainform mainform;
	mainform.DisplyOpenDefine();
	cout<<"���������ϢΪ:"<<endl;
	cout<<"����:"<<strusername<<"\n"<<"���֤��:"<<strcardid<<"\n"<<"����:"<<struserpassword<<"\n"<<"�绰����:"<<struserphone<<"\n"<<"סַ:"<<struseradress<<endl;
	coperatefile p;
	p.readuserinfo();
	nuseraccount=p.findmaxcardid()+1;
	cout<<"�����˻�Ϊ:"<<nuseraccount<<"\n"<<"��ȷ���Ƿ񿪻�(Y/N)"<<endl;
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
			cout<<"������ɣ��밴���������"<<endl;
			getch();
			break;
		}
		else if(strdecision=="N"||strdecision=="n"){
			fout1.close();
			fout2.close();
			break;
		}
		else{
			cout<<"������Ĳ���ȷ"<<endl;
		}
	}
	return;
}
void ctransaction::deleteaccount(){
	int i=0;
	string strinput;
	cout<<"�������˺�:";
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
		cout<<"�����ɹ�,�����������"<<endl;
		p.saveaccountinfo();
		getch();
	}
	else{
		cout<<"����ʧ�ܣ������˺��Ƿ���ȷ�������������...."<<endl;
		getch();
	}
	return;
}
void ctransaction::leadincustomer(){
	string filename1;
	string filename2;
	filename1="user.txt";
	cout<<"��������Ҫ������ļ���:";
	cin>>filename2;
	coperatefile p;
	ifstream fin;
	fin.open(&filename2[0]);
	if(!fin.is_open()){
		cout<<"�ļ��޷���ȡ�����֤���������룬�����������..."<<endl;
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
		cout<<"�������,�����������"<<endl;
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
	cout<<"�������û���:";
	cin>>strusername;
	filename="content.txt";
	fin.open("user.txt");
	if(!fin.is_open()){
		cout<<"�����⣬�����������"<<endl;
		getch();
	}
	else{
		fin.close();
		p.readuserinfo();
		p.saveuserinfo(&filename[0]);
		cout<<"�����ɹ��������������"<<endl;
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
	cout<<"����������˺�:";
	cin>>accountnum;
	cout<<"����������:";
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
		cout<<"���ɹ��������������..."<<endl;
		getch();
	}
	else{
		cout<<"�Ҳ������˺ţ������������..."<<endl;
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
	cout<<"�������˺�:";
	cin>>naccountnum;
	cout<<"1.100  2.200  3.500  4.1000  5.����"<<endl;
	cout<<"������ȡ����:";
	cin>>ntype;
	while(1){
		if(ntype>5||ntype<1){
			cout<<"�����������������..."<<endl;
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
		cout<<"�������������������Σ��������ҵ��..."<<endl;
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
					cout<<"����"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-100;
					break;
				}
			case 2:
				if(200>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"����"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-200;
					return;
				}
			case 3:
					if(500>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"����"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-500;
					break;
				}
			case 4:
					if(1000>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"����"<<endl;
					return;
				}
				else{
					nmoney=atoi(paccountinfo->account->getbalance().c_str())-1000;
					break;
				}
			case 5:
				cout<<"������ȡ������:";
				cin>>ndrawmoney;
				if(ndrawmoney>atoi(paccountinfo->account->getbalance().c_str())){
					cout<<"����"<<endl;
					return;
				}
				else if(ndrawmoney%100!=0||ndrawmoney>=2500){
					cout<<"���������!"<<endl;
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
		cout<<"��ȡ�������ֽ𣬰�������˳�..."<<endl;
		getch();
	}
	else{
		cout<<"�Ҳ������˺ţ����֤����������..."<<endl;
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
	cout<<"������ת���˻���:";
	cin>>accountnum1;
	cout<<"������ת���˻���:";
	cin>>accountnum2;
	cout<<"������ת�˽��:";
	cin>>ntransmoney;
	if(accountnum1==accountnum2){
		cout<<"�������,���������"<<endl;
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
		cout<<"�˻���Ч�����֤���������룬�����������..."<<endl;
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
						cout<<"����!"<<endl;
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
	cout<<"ת�˳ɹ�"<<endl;
	return;
}
void ctransaction::checkbalance(){
	coperatefile p;
	int i=0;
	long int naccountnum;
	string strbalance;
	cout<<"�������˻�:"<<endl;
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
		cout<<"�˻����Ϊ:"<<strbalance<<"Ԫ"<<endl;
	}
	else{
		cout<<"�˻������ڣ���������˳�!"<<endl;
		getch();
		return;
	}
	return;
}























