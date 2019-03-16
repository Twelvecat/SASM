#ifndef HEADER_STUDENT
#define HEADER_STUDENT
#include <iostream>
#include <string>
using namespace std;
class Student {
	string m_id; //学生学号
	string m_name; //学生姓名
	short int m_math;  //学生成绩，下同
	short int m_physics;
	short int m_english;
public:
	Student(string id = 0, string name = "nill", short int math = 0, short int physics = 0, short int english = 0) :
		m_id(id), m_name(name), m_math(math), m_physics(physics), m_english(english){}
	~Student() {}

	string showid() const;//读取一个学生的学号，下同
	string showname() const;
	short int showmath() const;
	short int showenglish() const;
	short int showphysics() const;
	short int showall() const;

	void setid(const string &id);//修改一个学生的学号，下同
	void setname(const string &name);
	void setmath(const short int &math);
	void setenglish(const short int &english);
	void setphysics(const short int &physics);
	//void setall(const short int &all);

	friend ostream &operator <<(ostream &os, const Student &a);
	friend istream &operator >>(istream &is,  Student &a);
};
ostream &operator <<(ostream &os, const Student &a);
istream &operator >>(istream &is, Student &a);
#endif
