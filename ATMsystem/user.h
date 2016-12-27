#ifndef USER_C
#define USER_C
#include<iostream>
#include<string>
#include"form.h"
#include"coperatefile.h"
#include"ctransaction.h"
using namespace std;
static cmainform mainform;
static int g_naccount=0;//为了获取用户账号是否存在,0-销户,1-存在
class ccommonuser{
public:
	int userlogin();
	void useroperate();
};
class cmanager{
public:
	int managerlogin();
	void manageroperate();
};
#endif