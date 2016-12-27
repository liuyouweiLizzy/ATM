#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include"form.h"
#include"user.h"
#include"caccountinfo.h"
#include"ccustomer.h"
#include"ctransaction.h"
#include"coperatefile.h"
using namespace std;
int main(){
	int input;
	ccommonuser commonuser;
	cmanager manager;
	cmainform mainform;
	mainform.DisplyWelcome();
	while(1){
		cout<<"请选择身份>>";
		cin>>input;
		if(input==0){
			break;
		}
		else if(input==1){
			system("cls");
			int	i=manager.managerlogin();
			if(i==0){
				break;
			}
			else{
				manager.manageroperate();
				system("cls");
				mainform.DisplyWelcome();
			}
		}
		else if(input==2){
			system("cls");
			int j=commonuser.userlogin();
			if(j==0){
				break;
			}
			else{
				commonuser.useroperate();
				system("cls");
				mainform.DisplyWelcome();
			}
		}
		else if(input==3){
			system("cls");
			mainform.DisplyWelcome();
			cout<<"请按任意键返回!"<<endl;
			getch();
			system("cls");
		}
		else{
			cout<<"输入错误，请重新输入!"<<endl;
			mainform.DisplyWelcome();
		}
	}
	return 0;	
}
