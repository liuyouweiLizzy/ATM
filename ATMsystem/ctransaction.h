/*��Ҫ��������һϵ�еĲ��������翪�����������û����û�ȡ���ѯ��ת�˵�*/
#ifndef CTRANSACTION_C
#define CTRANSACTION_C
#include<iostream>
#include<fstream>
#include<string>
#include"coperatefile.h"
#include"ccustomer.h"
#include"form.h"
using namespace std;
class ctransaction{
public:
	ctransaction();
	ctransaction(long int);
	~ctransaction();
	void setaccountnum(long int);//�����˻�
	void openaccount();//����
	void deleteaccount();//����
        void leadincustomer();
        void leadoutcustomer();
	void deposite();//��Ǯ
	void withdraw();//ȡǮ
	void tranfer();//ת��
	void checkbalance();//��ѯ���
private:
	long int useraccount;
};
#endif
