#ifndef USER_C
#define USER_C
#include<iostream>
#include<string>
#include"form.h"
#include"coperatefile.h"
#include"ctransaction.h"
using namespace std;
static cmainform mainform;
static int g_naccount=0;//Ϊ�˻�ȡ�û��˺��Ƿ����,0-����,1-����
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