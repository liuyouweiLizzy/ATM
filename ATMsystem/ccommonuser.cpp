#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include"user.h"
using namespace std;
int ccommonuser::userlogin(){
	int i=0,ntype=0,nflag=0,num=0;
	string strpassword,straccountnum;
	long int naccountnum;
	char chone;
	ifstream fin;
	fin.open("user.txt");
	if(!fin.is_open()){
		cout<<"�����û��޷���¼"<<endl;
		return 0;
	}
	coperatefile p;
	p.readaccountinfo();
	caccountinfodata *paccountinfo=NULL;
	paccountinfo=p.accountinfo;
	cout<<"�������˻���:";
	cin>>straccountnum;
	naccountnum=atoi(straccountnum.c_str());
	while(paccountinfo){
		if(paccountinfo->account->getaccountNum()==naccountnum){
			if(paccountinfo->account->getflag()==1){
				ntype=1;
				break;
			}
			if(paccountinfo->account->getflag()==0){
				break;
			}
		}
		else{
			paccountinfo=paccountinfo->pnext;
		}
	}
	if(ntype==0){
		cout<<"���û��ѱ�����!"<<endl;
		return 0;
	}
	if(ntype==1){
		//���˸о�������ֺ���Ҫ
		for(num=0;num!=3;++num){
			strpassword="";
			fflush(stdin);
			cout<<"����������:";
			while((chone=_getch())!=13){
				char chtemp=chone;
				if(chone==8&&i!=0){
					int len=strpassword.size();
					strpassword[len-1]=0;
					cout<<'\b';
					cout<<" ";
					cout<<'\b';
				}
				if(chone!=8){
					strpassword+=chone;
					cout<<"*";
					++i;
				}
			}
			if(paccountinfo->account->getpassword()==strpassword){
				cout<<"��ϲ�㣬��½�ɹ�!"<<endl;
				nflag=1;
				break;
			}
			else{
				cout<<"�Բ��𣬵�¼ʧ�ܣ���������������!"<<endl;
			}
		}
	}
	if(nflag==1){
		return 1;
	}
	if(num==3){
		cout<<"�������������������,��¼ʧ��!"<<endl;
		return 0;
	}
}
void ccommonuser::useroperate(){
	int input;
	cmainform mainform;
	ctransaction p;
	mainform.DisplyUserOperate();
	while(1){
		cout<<"���������ҵ����:";
		cin>>input;//���ڰ���ҵ�����ѭ����������Ӧ����ѭ����������ȻҲ������switch��������ʱ�Ͳ��ܹ�ѭ��������
		if(input==0){
			break;
		}
		else if(input==1){
			system("cls");
			mainform.DisplyDeposite();
			p.deposite();
			system("cls");
			mainform.DisplyUserOperate();
		}
		else if(input==2){
			system("cls");
			mainform.DisplyWithdraw();
			p.withdraw();
			system("cls");
			mainform.DisplyUserOperate();
		}
		else if(input==3){
			system("cls");
			mainform.DisplyCheckBalance();
			p.checkbalance();
			system("cls");
			mainform.DisplyUserOperate();
		}
		else if(input==4){
			system("cls");
			mainform.DisplyTransferAccount();
			p.tranfer();
			system("cls");
			mainform.DisplyUserOperate();
		}
		else{
			cout<<"�����������������!"<<endl;
		}
	}
	return;
}












