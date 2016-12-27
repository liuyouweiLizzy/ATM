#include"caccountinfo.h"
#include<iostream>
#include<string>
using namespace std;
caccountinfo::caccountinfo(long int num,const string &password,const string &balance,int f):accountnum(num),accountpassword(password),accountbalance(balance),flag(f){}
caccountinfo::~caccountinfo(){}
void caccountinfo::setaccountNum(long int num){
	accountnum=num;
	return;
}
void caccountinfo::setbalance(const string &strbalance){
	accountbalance=strbalance;
	return;
}//他当然不需要返回值，返回值的话就是说他是一个值的存在，这里用void则调用这个函数时会自动改变数据成员的值。
void caccountinfo::setpassword(const string &strpassword){
	accountpassword=strpassword;
	return;
}
void caccountinfo::setflag(int f){
	flag=f;
	return;
}
long int caccountinfo::getaccountNum() const{
	return accountnum;
}
string caccountinfo::getpassword() const{
	return accountpassword;
}
string caccountinfo::getbalance() const{
	return accountbalance;
}
int caccountinfo::getflag() const{
	return flag;
}