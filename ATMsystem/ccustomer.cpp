#include<iostream>
#include<string>
#include"ccustomer.h"
using namespace std;
ccustomerinfo::ccustomerinfo(long int num,const string &name,const string &strphone,const string &stradress,const string &password,const string &card):
useraccount(num),username(name),userphone(strphone),useradress(stradress),userpassword(password),cardid(card){};
void ccustomerinfo::showcustomerinfo() const{
	cout<<useraccount<<"\n"<<username<<"\n"<<userpassword<<"\n"<<cardid<<"\n"<<userphone<<"\n"<<useradress<<endl;
	return;
}
ccustomerinfo::~ccustomerinfo(){}
ccustomerinfo& ccustomerinfo::operator=(const ccustomerinfo &user){
	useraccount=user.useraccount;
	username=user.username;
	userphone=user.userphone;
	useradress=user.userphone;
	useradress=user.useradress;
	userpassword=user.userpassword;
	cardid=user.cardid;
	return *this;
}
long int ccustomerinfo::getuseraccount() const{
	return useraccount;
}
string ccustomerinfo::getusername() const{
	return username;
}
string ccustomerinfo::getuserphone() const{
	return userphone;
}
string ccustomerinfo::getuseradress() const{
	return useradress;
}
string ccustomerinfo::getuserpassword() const{
	return userpassword;
}
string ccustomerinfo::getcardid() const{
	return cardid;
}
