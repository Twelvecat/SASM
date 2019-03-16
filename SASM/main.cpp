#include"manage.h"
#include"student.h"
#include"view.h"
#include<vector>
#include <iostream>
#include <string>
using namespace std;
Manage stum;
int main() {
	View list;//程序的初始化
	list.title();
	list.showmean();
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;//用来调用不同的视图层菜单
	while (choose!='0') {//输入0则退出本程序
		switch(choose) {
		case '1':
			list.addstu();
			break;
		case '2':
			list.delstd();
			break;
		case '3':
			list.newstd();
			break;
		case '4':
			list.findstd();
			break;
		case '5':
			list.showvalue();
			break;
		case '6':
			list.rank();
			break;
		case '7':
			list.readfile();
			break;
		case '8':
			list.writefile();
			break;
		case '9':
			list.blurry();
			break;
		default:
			system("cls");
			cout << "输入错误，请重新输入。" << endl;
			list.title();
			list.showmean();
		}
		cout << "请输入指令的序号：";
		cin >> choose;
	}
	return 0;
}