#ifndef HEADER_VIEW
#define HEADED_VIEW
#include"manage.h"
#include"student.h"
#include<iostream>
extern Manage stum;
using namespace std;
class View {
public:
	View();
	~View() {}
	void title();
	void showmean();//主菜单
	void showallstu();
	void addstu();//增加学生
	void delstd();
	void newstd();
	void newlist(const int&i);
	void findstd();
	void readfile();
	void writefile();
	void showvalue();//求班级管理
	void rank();
	void showaround();//求范围成绩
	void showage();
	void showpass();
	void showstd();
	void blurry();
private:
};
#endif