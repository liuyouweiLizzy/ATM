#ifndef CACCOUNTINFO_C
#define CACCOUNTINFO_C
#include<iostream>
#include<string>
using namespace std;
class caccountinfo{
public:
        caccountinfo();
	caccountinfo(long int num,const string &password,const string &balance,int f);
	~caccountinfo();
	void setaccountNum(long int);
	void setbalance(const string&);
	void setpassword(const string&);
	void setflag(int);
	long int getaccountNum() const;
	string getpassword() const;
	string getbalance() const;
	int getflag() const;
private:
	long int accountnum;
	string accountpassword;
	string accountbalance;
	int flag;
};
#endif