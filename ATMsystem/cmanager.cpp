#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include"user.h"
using namespace std;
int cmanager::managerlogin(){
	string strname,strpassword;
	string name,password;
	int num=0,i=0,ntype=0;
	ifstream fin;
	char chone;
	fin.open("manager.txt");
	if(!fin.is_open()){
		cout<<"�ļ��򿪴���!"<<endl;
		return 0;
	}
	fin>>strname>>strpassword;
	fin.close();
	for(num=0;num!=3;++num){
		cout<<"�������û���:";
	    cin>>name;
		password="";
		fflush(stdin);
		cout<<"����������:";
		while((chone=_getch())!=13){
			char chtemp=chone;
			if(chtemp==8&&i!=0){
				int len=password.size();
				password[len-1]=0;
				cout<<"\b";
				cout<<" ";
				cout<<"\b";
			}
			if(chtemp!=8){
				password+=chone;
				cout<<"*";
				++i;
			}
		}
		if(strname==name){
			if(password==strpassword){
				cout<<"��ϲ�㣬��½�ɹ�!"<<endl;
				ntype=1;
				break;
			}
			else{
				cout<<"������������µ�½!"<<endl;
			}
		}
		else{
			cout<<"�û������������µ�½!"<<endl;
		}
	}
	if(ntype==1){
		return 1;
	}
	else{
		cout<<"������������������Σ���ʧЧ!"<<endl;
		return 0;
	}
}
void cmanager::manageroperate(){
	int input;
	cmainform mainform;
	ctransaction p;
	mainform.DisplyManageOperate();
	while(1){
		cin>>input;
		if(input==0){
			break;
		}
		else if(input==1){
			system("cls");
			mainform.DisplyOpenAccount();
			p.openaccount();
			system("cls");
			mainform.DisplyManageOperate();
		}
		else if(input==2){
			system("cls");
			mainform.DisplyDeleteAccount();
			p.deleteaccount();
			system("cls");
			mainform.DisplyManageOperate();
		}
		else if(input==3){
			system("cls");
			mainform.Displyleadin();
			p.leadincustomer();
			system("cls");
			mainform.DisplyManageOperate();
		}
		else if(input==4){
			system("cls");
			mainform.Displyleadout();
			p.leadoutcustomer();
			system("cls");
			mainform.DisplyManageOperate();
		}
		else{
			cout<<"���������������������!"<<endl;
			mainform.DisplyManageOperate();
		}
	}
	return;
}










