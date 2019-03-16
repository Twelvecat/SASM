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
			cout << "输入错误，请重新输入：";
		}
	} while (1);
}
View::View() {}
void View::title() {
	cout << "\n\t教务管理系统（Twelvecat开发）" << endl;
	cout << "\n================================================================" << endl;
}
void View::showmean() {
	cout << "1.学生成绩信息录入" << endl;
	cout << "2.学生成绩信息删除" << endl;
	cout << "3.学生成绩信息修改" << endl;
	cout << "4.学生成绩信息查询" << endl;
	cout << "5.班级分数情况统计" << endl;
	cout << "6.班级分数排序" << endl;
	cout << "7.打开成绩文件" << endl;
	cout << "8.保存至成绩文件" << endl;
	cout << "9.模糊查询" << endl;
	cout << "0.退出本系统" << endl;
	cout << "\n================================================================" << endl;
}
void View::addstu() { //视图层增加一个学生记录
	string id;
	string name;
	short int math;
	short int physics;
	short int english;
	int flag = 0;
	do {
		system("cls");
		title();
		cout << "请输入学生的学号：";
		cin >> id;
		cout << "请输入学生的姓名：";
		cin >> name;
		cout << "请输入学生的数学成绩：";
		cin >> math;
		cout << "请输入学生的物理成绩：";
		cin >> physics;
		cout << "请输入学生的英语成绩：";
		cin >> english;
		Student stu(id, name, math, physics, english);
		stum.add(stu);
		cout << "添加完毕，是否需要继续添加？y/n：";
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
	cout << "1.按学号查询需要删除的人" << endl;
	cout << "2.按姓名查询需要删除的人" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
		{string id;
		cout << "请输入学号：";
		cin >> id;
		if (stum.stu.size() == stum.show_id(id))cout << "未查找到该学生";
		else {
			int i = stum.show_id(id);
			cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
			cout << "是否需要删除该同学？y/n";
			if (sure()) {
				stum.del(i);//确定操作
				cout << "删除成功" << endl;
			}
		}
		system("pause");
		choose = '0';
		break; }
		case '2':
		{string name;
		string id;
		cout << "请输入姓名：";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "未查找到该学生";
		else {
			int i = stum.show_name(name);
			cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
			cout << "是否需要删除该同学？y/n";
			if (sure()) {
				stum.del(i);//确定操作
				cout << "删除成功" << endl;
			}
		}
		system("pause");
		choose = '0';
		break; }
		default:
			cout << "输入错误，请重新输入。" << endl;
			cin >> choose;
		}
	}
	system("cls");
	title();
	showmean();
}
void View::newlist(const int&i) {
	cout << "\n================================================================" << endl;
	cout << "1.修改学号" << endl;
	cout << "2.修改姓名" << endl;
	cout << "3.修改物理" << endl;
	cout << "4.修改数学" << endl;
	cout << "5.修改英语" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
		{cout << "请输入正确学号：";
		string id;
		cin >> id;
		stum.stu.at(i).setid(id);
		cout << "修改成功" << endl;
		choose = '0';
		break; }
		case '2':
		{cout << "请输入正确姓名：";
		string name;
		cin >> name;
		stum.stu.at(i).setname(name);
		cout << "修改成功" << endl;
		choose = '0';
		break; }
		case '3':
			cout << "请输入正确物理成绩：";
			short int physics;
			cin >> physics;
			stum.stu.at(i).setphysics(physics);
			cout << "修改成功" << endl;
			choose = '0';
			break;
		case '4':
			cout << "请输入正确数学成绩：";
			short int math;
			cin >> math;
			stum.stu.at(i).setmath(math);
			cout << "修改成功" << endl;
			choose = '0';
			break;
		case '5':
			cout << "请输入正确英语成绩：";
			short int english;
			cin >> english;
			stum.stu.at(i).setenglish(english);
			cout << "修改成功" << endl;
			choose = '0';
			break;
		default:
			cout << "输入错误，请重新输入:";
			cin >> choose;
		}
	}
}
void View::newstd() {
	system("cls");
	title();
	cout << "1.按学号查询需要修改的人" << endl;
	cout << "2.按姓名查询需要修改的人" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1': {
			string id;
			cout << "请输入学号：";
			cin >> id;
			if (stum.stu.size() == stum.show_id(id))cout << "未查找到该学生";
			else {
				int i = stum.show_id(id);
				cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
				newlist(i);
			}
			choose = '0';
			system("pause");
			break; }
		case '2':
		{string name;
		cout << "请输入姓名：";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "未查找到该学生";
		else {
			int i = stum.show_name(name);
			cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
			newlist(i);
		}
		choose = '0';
		system("pause");
		break; }
		default:
			cout << "输入错误，请重新输入。" << endl;
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
	cout << "1.查询物理成绩" << endl;
	cout << "2.查询数学成绩" << endl;
	cout << "3.查询英语成绩" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	int a, b;
	while (choose!='0') {
		switch (choose){
		case '1':
			cout << "请输入分数段（如60 80）：";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 1))cout << i << '\t';
			choose = '0';
			break;
		case '2':
			cout << "请输入分数段（如60 80）：";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 2))cout << i << '\t';
			choose = '0';
			break;
		case '3':
			cout << "请输入分数段（如60 80）：";
			cin >> a >> b;
			for (auto i : stum.show_score(a, b, 3))cout << i << '\t';
			choose = '0';
			break;
		default:
			cout << "输入错误，请重新输入：";
			cin >> choose;
		}
	}
}
void View::findstd() {
	system("cls");
	title();
	cout << "1.按学号查询" << endl;
	cout << "2.按姓名查询" << endl;
	cout << "3.按分数段查询" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
		{string id;
		cout << "请输入学号：";
		cin >> id;
		if (stum.stu.size() == stum.show_id(id))cout << "未查找到该学生";
		else {
			int i = stum.show_id(id);
			cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
		}
		choose = '0';
		break; }
		case '2':
		{string name;
		cout << "请输入姓名：";
		cin >> name;
		if (stum.stu.size() == stum.show_name(name))cout << "未查找到该学生";
		else {
			int i = stum.show_name(name);
			cout << "查询结果如下:\n" << stum.stu.at(i) << endl;
		}
		choose = '0';
		break; }
		case '3':
			showaround();
			choose = '0';
			break;
		default:
			cout << "输入错误，请重新输入：";
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
	cout << "1.全班平均分" << endl;
	cout << "2.物理平均分" << endl;
	cout << "3.数学平均分" << endl;
	cout << "4.英语平均分" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose){
		case '1':
			cout << "平均值为：" << stum.avg(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "平均值为：" << stum.avg(choose,1) << endl;
			choose = '0';
			break;
		case '3':
			cout << "平均值为：" << stum.avg(choose,1) << endl;
			choose = '0';
			break;
		case '4':
			cout << "平均值为：" << stum.avg(choose,1) << endl;
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
	cout << "1.物理及格率" << endl;
	cout << "2.数学及格率" << endl;
	cout << "3.英语及格率" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			cout << "及格率为：" << stum.pass_rate(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "及格率为：" << stum.pass_rate(choose) << endl;
			choose = '0';
			break;
		case '3':
			cout << "及格率为：" << stum.pass_rate(choose) << endl;
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
	cout << "1.全班标准差" << endl;
	cout << "2.物理标准差" << endl;
	cout << "3.数学标准差" << endl;
	cout << "4.英语标准差" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			cout << "标准差为：" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '2':
			cout << "标准差为：" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '3':
			cout << "标准差为：" << stum.standard_deviation(choose) << endl;
			choose = '0';
			break;
		case '4':
			cout << "标准差为：" << stum.standard_deviation(choose) << endl;
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
	cout << "1.查询平均分" << endl;
	cout << "2.查询及格率" << endl;
	cout << "3.查询标准差" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
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
			cout << "输入错误，请重新输入：";
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
	cout << "1.打开默认文件" << endl;
	cout << "2.打开新的文件" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1': 
			choose = '0';
			break;
		case '2':	cout << "请输入路径:" << endl;
			cin >> path;
			choose = '0';
			break;
		default:
			cout << "输入错误，请重新输入：";
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
	cout << "1.保存至默认文件" << endl;
	cout << "2.另存为" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "\n================================================================" << endl;
	char choose;
	cout << "请输入指令的序号：";
	cin >> choose;
	while (choose!='0') {
		switch (choose) {
		case '1':
			choose = '0';
			break;
		case '2':	
			cout << "请输入路径:" << endl;
			cin >> path;
			choose = '0';
			break;
		default:
			cout << "输入错误，请重新输入：";
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
	cout << "请输入查找对象姓名中所含有的关键词：";
	cin >> key;
	cout << "\n================================================================" << endl;
	cout << "1.按照学号排序" << endl;
	cout << "2.按照总分排序" << endl;
	cout << "3.按照数学排序" << endl;
	cout << "4.按照物理排序" << endl;
	cout << "5.按照英语排序" << endl;
	cout << "\n================================================================" << endl;
	cout << "请输入指令：";
	cin >> choose;
	system("cls");
	title();
	vector<int>value = stum.Blurry(key,choose);
	if (value.size()) {
		cout << "检索结果如下：" << endl;
		for (i = 0; i < value.size(); ++i) {
			cout << i << "." << stum.stu.at(value.at(i)).showname() << '\t';
		}
		cout << "-1.退出查询";
		cout << "\n================================================================" << endl;
		do {
			cout << "请输入你需要查找对象的序号并回车：";
			cin >> i;
			if (i == -1)break;
			cout << stum.stu.at(value.at(i)) << endl;
			cout << "\n================================================================" << endl;
		} while (1);
	}
	else {
		cout << "未搜寻到任何结果" << endl;
		cout << "\n================================================================" << endl;
	}
	system("pause");
	system("cls");
	title();
	showmean();
}