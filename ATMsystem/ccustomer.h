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
	long int useraccount;//用户账号
	string username;//用户名
	string userphone;//用户电话
	string useradress;//用户地址
	string userpassword;//用户密码
	string cardid;//用户身份证号
};
#endif