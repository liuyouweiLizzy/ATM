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
}//����Ȼ����Ҫ����ֵ������ֵ�Ļ�����˵����һ��ֵ�Ĵ��ڣ�������void������������ʱ���Զ��ı����ݳ�Ա��ֵ��
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