#ifndef CCUSTOMER_C
#define CCUSTOMER_C
#include<iostream>
#include<string>
using namespace std;
class ccustomerinfo{
public:
	ccustomerinfo();
	ccustomerinfo(long int account,const string &name,const string &phone,const string &adress,const string &password,const string &cardid);
	~ccustomerinfo();
	void showcustomerinfo() const;
        ccustomerinfo& operator=(const ccustomerinfo&);
	long int getuseraccount() const;
	string getusername() const;
	string getuserphone() const;
	string getuseradress() const;
	string getuserpassword() const;
	string getcardid() const;
private:
	long int useraccount;//�û��˺�
	string username;//�û���
	string userphone;//�û��绰
	string useradress;//�û���ַ
	string userpassword;//�û�����
	string cardid;//�û����֤��
};
#endif