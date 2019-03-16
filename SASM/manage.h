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
	void add(const Student &a);//增加一个学生记录
	void del(int &i);//删除一个学生
	int show_id(const string &id);//通过学号查找然后返回该学生的序号（在vector中的下角标）
	int show_name(const string &name);//通过姓名查找然后返回该学生的序号（在vector中的下角标）
	vector<string> show_score(const int &a,const int &b,const int &c);//查询指定分数段的人
	float avg(const char &choose);//查询全班的平均成绩
	float avg(const char &choose,const char &flag);//查询单科的平均成绩
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