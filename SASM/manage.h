//#ifndef HEADER_MANAGE
//#define HEADED_MANAGE
#pragma once
#include "student.h"
#include <vector>
#include<sstream>
#include<fstream>
using namespace std;
class Manage {
public:
	Manage();
	~Manage() {}
	void add(const Student &a);//����һ��ѧ����¼
	void del(int &i);//ɾ��һ��ѧ��
	int show_id(const string &id);//ͨ��ѧ�Ų���Ȼ�󷵻ظ�ѧ������ţ���vector�е��½Ǳ꣩
	int show_name(const string &name);//ͨ����������Ȼ�󷵻ظ�ѧ������ţ���vector�е��½Ǳ꣩
	vector<string> show_score(const int &a,const int &b,const int &c);//��ѯָ�������ε���
	float avg(const char &choose);//��ѯȫ���ƽ���ɼ�
	float avg(const char &choose,const char &flag);//��ѯ���Ƶ�ƽ���ɼ�
	double standard_deviation(const char &choose);
	double pass_rate(const char &choose);
	void rank();
	void read_file(const string &path);
	void write_file(const string &path);
	vector<int> Blurry(const string &key, const int choose);
	vector<Student>stu;
	void blurry_rook(vector<int> &value,const int choose);
private:
};
//#endif