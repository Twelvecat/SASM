#include "view.h"
#include<iostream>
#include<string>
using namespace std;
bool sure() {
	char choose;
	do {
		cin >> choose;
		if (choose == 'y' || choose == 'Y')return 1;
		else if (choose == 'n' || choose == 'N') return 0;
		else {
			cout << "����������������룺";
		}
	} while (1);
}
View::View() {}
void View::title() {
	cout << "\n\t�������ϵͳ��Twelvecat������" << endl;
	cout << "\n================================================================" << endl;
}
void View::showmean() {
	cout << "1.ѧ���ɼ���Ϣ¼��" << endl;
	cout << "2.ѧ���ɼ���Ϣɾ��" << endl;
	cout << "3.ѧ���ɼ���Ϣ�޸�" << endl;
	cout << "4.ѧ���ɼ���Ϣ��ѯ" << endl;
	cout << "5.�༶�������ͳ��" << endl;
	cout << "6.�༶��������" << endl;
	cout << "7.�򿪳ɼ��ļ�" << endl;
	cout << "8.�������ɼ��ļ�" << endl;
	cout << "9.ģ����ѯ" << endl;
	cout << "0.�˳���ϵͳ" << endl;
	cout << "\n================================================================" << endl;
}
void View::addstu() { //��ͼ������һ��ѧ����¼
	string id;
	string name;
	short int math;
	short int physics;
	short int english;
	int flag = 0;
	do {
		system("cls");
		title();
		cout << "������ѧ����ѧ�ţ�";
		cin >> id;
		cout << "������ѧ����������";
		cin >> name;
		cout << "������ѧ������ѧ�ɼ���";
		cin >> math;
		cout << "������ѧ��������ɼ���";
		cin >> physics;
		cout << "������ѧ����Ӣ��ɼ���";
		cin >> english;
		Student stu(id, name, math, physics, english);
		stum.add(stu);
		cout << "�����ϣ��Ƿ���Ҫ������ӣ�y/n��";
		if (sure())flag = 1;
		else flag = 0;
	} while (flag);
	system("cls");
	title();
	showmean();
}
void View::delstd() {
	system("cls");
	title();
	cout << "1.��ѧ�Ų�ѯ��Ҫɾ������" << endl;
	cout << "2.��������ѯ��Ҫɾ������" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
		{string id;
		cout << "������ѧ�ţ�";
		cin >> id;
		if (stum.stu.size() == stum.show_id(id))cout << "δ���ҵ���ѧ��";
		else {
			int i = stum.show_id(id);
			cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
			cout << "�Ƿ���Ҫɾ����ͬѧ��y/n";
			if (sure()) {
				stum.del(i);//ȷ������
				cout << "ɾ���ɹ�" << endl;
			}
		}
		system("pause");
		choose = '0';
		break; }
		case '2':
		{string name;
		string id;
		cout << "������������";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "δ���ҵ���ѧ��";
		else {
			int i = stum.show_name(name);
			cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
			cout << "�Ƿ���Ҫɾ����ͬѧ��y/n";
			if (sure()) {
				stum.del(i);//ȷ������
				cout << "ɾ���ɹ�" << endl;
			}
		}
		system("pause");
		choose = '0';
		break; }
		default:
			cout << "����������������롣" << endl;
			cin >> choose;
		}
	}
	system("cls");
	title();
	showmean();
}
void View::newlist(const int&i) {
	cout << "\n================================================================" << endl;
	cout << "1.�޸�ѧ��" << endl;
	cout << "2.�޸�����" << endl;
	cout << "3.�޸�����" << endl;
	cout << "4.�޸���ѧ" << endl;
	cout << "5.�޸�Ӣ��" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
		{cout << "��������ȷѧ�ţ�";
		string id;
		cin >> id;
		stum.stu.at(i).setid(id);
		cout << "�޸ĳɹ�" << endl;
		choose = '0';
		break; }
		case '2':
		{cout << "��������ȷ������";
		string name;
		cin >> name;
		stum.stu.at(i).setname(name);
		cout << "�޸ĳɹ�" << endl;
		choose = '0';
		break; }
		case '3':
			cout << "��������ȷ����ɼ���";
			short int physics;
			cin >> physics;
			stum.stu.at(i).setphysics(physics);
			cout << "�޸ĳɹ�" << endl;
			choose = '0';
			break;
		case '4':
			cout << "��������ȷ��ѧ�ɼ���";
			short int math;
			cin >> math;
			stum.stu.at(i).setmath(math);
			cout << "�޸ĳɹ�" << endl;
			choose = '0';
			break;
		case '5':
			cout << "��������ȷӢ��ɼ���";
			short int english;
			cin >> english;
			stum.stu.at(i).setenglish(english);
			cout << "�޸ĳɹ�" << endl;
			choose = '0';
			break;
		default:
			cout << "�����������������:";
			cin >> choose;
		}
	}
}
void View::newstd() {
	system("cls");
	title();
	cout << "1.��ѧ�Ų�ѯ��Ҫ�޸ĵ���" << endl;
	cout << "2.��������ѯ��Ҫ�޸ĵ���" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1': {
			string id;
			cout << "������ѧ�ţ�";
			cin >> id;
			if (stum.stu.size() == stum.show_id(id))cout << "δ���ҵ���ѧ��";
			else {
				int i = stum.show_id(id);
				cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
				newlist(i);
			}
			choose = '0';
			system("pause");
			break; }
		case '2':
		{string name;
		cout << "������������";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "δ���ҵ���ѧ��";
		else {
			int i = stum.show_name(name);
			cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
			newlist(i);
		}
		choose = '0';
		system("pause");
		break; }
		default:
			cout << "����������������롣" << endl;
			cin >> choose;
		}
	}
	system("cls");
	title();
	showmean();
}
void View::showaround(){
	system("cls");
	title();
	cout << "1.��ѯ����ɼ�" << endl;
	cout << "2.��ѯ��ѧ�ɼ�" << endl;
	cout << "3.��ѯӢ��ɼ�" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	int a, b;
	while (choose!='0') {
		switch (choose){
		case '1':
			cout << "����������Σ���60 80����";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 1))cout << i << '\t';
			choose = '0';
			break;
		case '2':
			cout << "����������Σ���60 80����";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 2))cout << i << '\t';
			choose = '0';
			break;
		case '3':
			cout << "����������Σ���60 80����";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 3))cout << i << '\t';
			choose = '0';
			break;
		default:
			cout << "����������������룺";
			cin >> choose;
		}
	}
}
void View::findstd() {
	system("cls");
	title();
	cout << "1.��ѧ�Ų�ѯ" << endl;
	cout << "2.��������ѯ" << endl;
	cout << "3.�������β�ѯ" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
		{string id;
		cout << "������ѧ�ţ�";
		cin >> id;
		if (stum.stu.size() == stum.show_id(id))cout << "δ���ҵ���ѧ��";
		else {
			int i = stum.show_id(id);
			cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
		}
		choose = '0';
		break; }
		case '2':
		{string name;
		cout << "������������";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "δ���ҵ���ѧ��";
		else {
			int i = stum.show_name(name);
			cout << "��ѯ�������:\n" << stum.stu.at(i) << endl;
		}
		choose = '0';
		break; }
		case '3':
			showaround();
			choose = '0';
			break;
		default:
			cout << "����������������룺";
			cin >> choose;
		}
	}
	system("pause");
	system("cls");
	title();
	showmean();
}
void View::showage() {
	system("cls");
	title();
	cout << "1.ȫ��ƽ����" << endl;
	cout << "2.����ƽ����" << endl;
	cout << "3.��ѧƽ����" << endl;
	cout << "4.Ӣ��ƽ����" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
			cout << "ƽ��ֵΪ��" << stum.avg(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "ƽ��ֵΪ��" << stum.avg(choose,1) << endl;
			choose = '0';
			break;
		case '3':
			cout << "ƽ��ֵΪ��" << stum.avg(choose,1) << endl;
			choose = '0';
			break;
		case '4':
			cout << "ƽ��ֵΪ��" << stum.avg(choose,1) << endl;
			choose = '0';
			break;
		default:
			break;
		}
	}
}
void View::showpass() {
	system("cls");
	title();
	cout << "1.��������" << endl;
	cout << "2.��ѧ������" << endl;
	cout << "3.Ӣ�Ｐ����" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			cout << "������Ϊ��" << stum.pass_rate(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "������Ϊ��" << stum.pass_rate(choose) << endl;
			choose = '0';
			break;
		case '3':
			cout << "������Ϊ��" << stum.pass_rate(choose) << endl;
			choose = '0';
			break;
		default:
			break;
		}
	}
}
void View::showstd() {
	system("cls");
	title();
	cout << "1.ȫ���׼��" << endl;
	cout << "2.�����׼��" << endl;
	cout << "3.��ѧ��׼��" << endl;
	cout << "4.Ӣ���׼��" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			cout << "��׼��Ϊ��" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "��׼��Ϊ��" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '3':
			cout << "��׼��Ϊ��" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '4':
			cout << "��׼��Ϊ��" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		default:
			break;
		}
	}
}
void View::showvalue() {
	system("cls");
	title();
	cout << "1.��ѯƽ����" << endl;
	cout << "2.��ѯ������" << endl;
	cout << "3.��ѯ��׼��" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			showage();
			choose = '0';
			break;
		case '2':
			showpass();
			choose = '0';
			break; 
		case '3':
			showstd();
			choose = '0';
			break;
		default:
			cout << "����������������룺";
			cin >> choose;
		}
	}
	system("pause");
	system("cls");
	title();
	showmean();
}
void View::showallstu() {
	for (int i = stum.stu.size() - 1; i!=-1; --i) {
		cout << stum.stu.at(i) << endl;
	}
	cout << "\n================================================================" << endl;
}
void View::rank() {
	system("cls");
	title();
	stum.rank();
	showallstu();
	system("pause");
	system("cls");
	title();
	showmean();
}
void View::readfile() {
	string path = "data.txt";
	system("cls");
	title();
	cout << "1.��Ĭ���ļ�" << endl;
	cout << "2.���µ��ļ�" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1': 
			choose = '0';
			break;
		case '2':	cout << "������·��:" << endl;
			cin >> path;
			choose = '0';
			break;
		default:
			cout << "����������������룺";
			cin >> choose;
		}
		stum.read_file(path);
		system("cls");
		title();
		showallstu();
		system("pause");
	}
	system("cls");
	title();
	showmean();
}
void View::writefile() {
	string path = "D:\\Others\\SASM\\SASM\\SASM\\data.txt";
	system("cls");
	title();
	cout << "1.������Ĭ���ļ�" << endl;
	cout << "2.���Ϊ" << endl;
	cout << "0.�������˵�" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "������ָ�����ţ�";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			choose = '0';
			break;
		case '2':	
			cout << "������·��:" << endl;
			cin >> path;
			choose = '0';
			break;
		default:
			cout << "����������������룺";
			cin >> choose;
		}
		stum.write_file(path);
		title();
		showallstu();
		system("pause");
	}
	system("cls");
	title();
	showmean();
}
void View::blurry() {
	system("cls");
	title();
	string key;
	int i;
	int choose;
	cout << "��������Ҷ��������������еĹؼ��ʣ�";
	cin >> key;
	cout << "\n================================================================" << endl;
	cout << "1.����ѧ������" << endl;
	cout << "2.�����ܷ�����" << endl;
	cout << "3.������ѧ����" << endl;
	cout << "4.������������" << endl;
	cout << "5.����Ӣ������" << endl;
	cout << "\n================================================================" << endl;
	cout << "������ָ�";
	cin >> choose;
	system("cls");
	title();
	vector<int>value = stum.Blurry(key,choose);
	if (value.size()) {
		cout << "����������£�" << endl;
		for (i = 0; i < value.size(); ++i) {
			cout << i << "." << stum.stu.at(value.at(i)).showname() << '\t';
		}
		cout << "-1.�˳���ѯ";
		cout << "\n================================================================" << endl;
		do {
			cout << "����������Ҫ���Ҷ������Ų��س���";
			cin >> i;
			if (i == -1)break;
			cout << stum.stu.at(value.at(i)) << endl;
			cout << "\n================================================================" << endl;
		} while (1);
	}
	else {
		cout << "δ��Ѱ���κν��" << endl;
		cout << "\n================================================================" << endl;
	}
	system("pause");
	system("cls");
	title();
	showmean();
}