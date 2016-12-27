#ifndef COPERATEFILE_C
#define COPERATEFILE_C
#include<iostream>
#include<fstream>
#include<string>
#include"ccustomer.h"
#include"caccountinfo.h"
using namespace std;
//�û�������Ϣ��
class ccustomerinfodata{
public:
	ccustomerinfo *user;
	ccustomerinfodata *pnext;
	ccustomerinfodata(){
		user=NULL;
		pnext=NULL;
	}
};
//�û��˻���Ϣ��
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
	ccustomerinfodata *customerinfo;//ָ���û���Ϣ��Ľڵ�
	caccountinfodata *accountinfo;//ָ���˻���Ϣ��
	coperatefile();
	~coperatefile();
	void readuserinfo();//��ȡ�����û���Ϣ���ļ�
	void readuserinfo(char*);//��ȡ�������û���Ϣ���ļ�
	void readaccountinfo();//��ȡ�����û��˻���Ϣ
	void saveuserinfo();//��ȡ֮���޸��˵Ļ��϶���Ҫ���´���ģ�����ֱ�����ӵ��û���Ϣ���ⶼ�ǿ��ܵ�
	void saveaccountinfo();//ͬ���ı����˻���Ϣ
	void saveuserinfo(char*);//���޸��˵ı�������ļ���Ϣ��������
	long int findmaxcardid();//��ȡ����˻���
};
#endif






