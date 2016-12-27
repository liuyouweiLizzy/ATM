/*主要用来保存一系列的操作，比如开户，销户，用户存款，用户取款，查询余额，转账等*/
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
	void setaccountnum(long int);//设置账户
	void openaccount();//开户
	void deleteaccount();//销户
        void leadincustomer();
        void leadoutcustomer();
	void deposite();//存钱
	void withdraw();//取钱
	void tranfer();//转账
	void checkbalance();//查询余额
private:
	long int useraccount;
};
#endif
