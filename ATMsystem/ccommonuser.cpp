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
		cout<<"现在用户无法登录"<<endl;
		return 0;
	}
	coperatefile p;
	p.readaccountinfo();
	caccountinfodata *paccountinfo=NULL;
	paccountinfo=p.accountinfo;
	cout<<"请输入账户号:";
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
		cout<<"该用户已被销户!"<<endl;
		return 0;
	}
	if(ntype==1){
		//个人感觉这个部分很重要
		for(num=0;num!=3;++num){
			strpassword="";
			fflush(stdin);
			cout<<"请输入密码:";
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
				cout<<"恭喜你，登陆成功!"<<endl;
				nflag=1;
				break;
			}
			else{
				cout<<"对不起，登录失败，请重新输入密码!"<<endl;
			}
		}
	}
	if(nflag==1){
		return 1;
	}
	if(num==3){
		cout<<"您的输入次数超过三次,登录失败!"<<endl;
		return 0;
	}
}
void ccommonuser::useroperate(){
	int input;
	cmainform mainform;
	ctransaction p;
	mainform.DisplyUserOperate();
	while(1){
		cout<<"请输入办理业务编号:";
		cin>>input;//由于办理业务可以循环办理，所以应该用循环来做，当然也可以用switch，但是这时就不能够循环来做了
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
			cout<<"输入错误，请重新输入!"<<endl;
		}
	}
	return;
}












