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
	void showmean();//���˵�
	void showallstu();
	void addstu();//����ѧ��
	void delstd();
	void newstd();
	void newlist(const int&i);
	void findstd();
	void readfile();
	void writefile();
	void showvalue();//��༶����
	void rank();
	void showaround();//��Χ�ɼ�
	void showage();
	void showpass();
	void showstd();
	void blurry();
private:
};
#endif