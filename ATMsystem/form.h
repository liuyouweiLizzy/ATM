#ifndef FORM_C
#define FORM_C
#include<iostream>
#include<string>
using namespace std;
class cmainform{
public:
	void DisplyWelcome();//present welcome
	void DisplyManageOperate();//present Manage operate
	void DisplyOpenAccount();//present open account
	void Displyleadin();//present defined open
	void DisplyDeleteAccount();//present delete account
	void Displyleadout();//present defined delete
	void DisplyUserOperate();//present user operate
	void DisplyDeposite();//present 存款
	void DisplyWithdraw();//present 取款
	void DisplyCheckBalance();//查询余额
	void DisplyTransferAccount();//转账
};
#endif