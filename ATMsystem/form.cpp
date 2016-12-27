#include<iostream>
#include"form.h"
using namespace std;
void cmainform::DisplyWelcome(){
	cout<<"\n\n       欢迎进入银行ATM操作系统 \n"<<endl;
	cout<<"           【1.操 作 员】"<<endl;
	cout<<"           【2.普通用户】"<<endl;
	cout<<"           【3.帮    助】"<<endl;
	cout<<"           【0.退    出】"<<endl;
	return;
}
void cmainform::DisplyManageOperate(){
	cout<<"           欢迎进入管理员操作界面\n\n"<<endl;
	cout<<"              【1.开       户】      "<<endl;
	cout<<"              【2.销       户】      "<<endl;
	cout<<"              【3.导 入 信 息】      "<<endl;
	cout<<"              【4.导 出 信 息】      "<<endl;
	cout<<"              【0.返       回】      "<<endl;
	cout<<">>请选择:";
	return;
}
void cmainform::DisplyOpenAccount(){
	cout<<"          开    户    确    认  "<<endl;
	return;
}
void cmainform::DisplyDeleteAccount(){
	cout<<"          销    户    确    认  "<<endl;
	return;
}
void cmainform::Displyleadin(){
	cout<<"          导    入    信    息  "<<endl;
	return;
}
void cmainform::Displyleadout(){
	cout<<"          导    出    信    息  "<<endl;
	return;
}
void cmainform::DisplyUserOperate(){
	cout<<"           欢迎进入用户操作界面\n\n"<<endl;
	cout<<"      【1.存 款】         【2.取 款】   "<<endl;
	cout<<"      【3.查 询】         【4.转 账】   "<<endl;
	cout<<"      【5.查询业务清单】  【0.返 回】   "<<endl;
	return;
}
void cmainform::DisplyDeposite(){
	cout<<"          存    款    业    务  "<<endl;
	return;
}
void cmainform::DisplyWithdraw(){
	cout<<"          取    款    业    务  "<<endl;
	return;
}
void cmainform::DisplyCheckBalance(){
	cout<<"          查    询    余    额  "<<endl;
	return;
}
void cmainform::DisplyTransferAccount(){
	cout<<"          转    账    业    务  "<<endl;
	return;
}




