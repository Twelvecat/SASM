#include "student.h"
ostream &operator <<(ostream &os, const Student &a) {
	os << "学号：" << a.showid() << '\t' << "姓名：" << a.showname() << '\t' << "物理：" << a.showphysics() << '\t' << "数学：" << a.showmath() << '\t' << "英语：" << a.showenglish() << '\t' << "总分：" << a.showall() << endl;
	return os;
}
istream &operator >>(istream &is, Student &a) {
	cout << "请输入学号：";
	is >> a.m_id;
	cout << "请输入姓名：";
	is >> a.m_name;
	cout << "请输入物理成绩：";
	is >> a.m_physics;
	cout << "请输入数学成绩：";
	is >> a.m_math;
	cout << "请输入英语成绩：";
	is >> a.m_english;
	cout << "设置完成" << endl;
	return is;
}
string Student::showid() const { return m_id; }
string Student::showname() const { return m_name; }
short int Student::showmath() const { return m_math; }
short int Student::showenglish() const { return m_english; }
short int Student::showphysics() const { return m_physics; }
short int Student::showall() const { return m_english+m_physics+m_math; }

void Student::setid(const string &id) { m_id = id; }
void Student::setname(const string &name) { m_name = name; }
void Student::setmath(const short int &math) { m_math = math; }
void Student::setenglish(const short int &english) { m_english = english; }
void Student::setphysics(const short int &physics) { m_physics = physics; }