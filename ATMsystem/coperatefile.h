#ifndef COPERATEFILE_C
#define COPERATEFILE_C
#include<iostream>
#include<fstream>
#include<string>
#include"ccustomer.h"
#include"caccountinfo.h"
using namespace std;
//用户链表信息类
class ccustomerinfodata{
public:
	ccustomerinfo *user;
	ccustomerinfodata *pnext;
	ccustomerinfodata(){
		user=NULL;
		pnext=NULL;
	}
};
//用户账户信息类
class caccountinfodata{
public:
	caccountinfo *account;
	caccountinfodata *pnext;
	caccountinfodata(){
		account=NULL;
		pnext=NULL;
	}
};
class coperatefile{
public:
	ccustomerinfodata *customerinfo;//指向用户信息类的节点
	caccountinfodata *accountinfo;//指向账户信息类
	coperatefile();
	~coperatefile();
	void readuserinfo();//读取保存用户信息的文件
	void readuserinfo(char*);//读取被导入用户信息的文件
	void readaccountinfo();//读取保存用户账户信息
	void saveuserinfo();//读取之后修改了的话肯定是要重新存入的，或者直接增加的用户信息，这都是可能的
	void saveaccountinfo();//同样的保存账户信息
	void saveuserinfo(char*);//将修改了的被导入的文件信息保存起来
	long int findmaxcardid();//获取最大账户号
};
#endif






