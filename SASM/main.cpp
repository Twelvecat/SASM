#include"manage.h"
#include"student.h"
#include"view.h"
#include<vector>
#include <iostream>
#include <string>
using namespace std;
Manage stum;
int main() {
	View list;//����ĳ�ʼ��
	list.title();
	list.showmean();
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;//�������ò�ͬ����ͼ��˵�
	while (choose!='0') {//����0���˳�������
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
			cout << "����������������롣" << endl;
			list.title();
			list.showmean();
		}
		cout << "������ָ�����ţ�";
		cin >> choose;
	}
	return 0;
}