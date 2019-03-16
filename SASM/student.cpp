#include "student.h"
ostream &operator <<(ostream &os, const Student &a) {
	os << "ѧ�ţ�" << a.showid() << '\t' << "������" << a.showname() << '\t' << "����" << a.showphysics() << '\t' << "��ѧ��" << a.showmath() << '\t' << "Ӣ�" << a.showenglish() << '\t' << "�ܷ֣�" << a.showall() << endl;
	return os;
}
istream &operator >>(istream &is, Student &a) {
	cout << "������ѧ�ţ�";
	is >> a.m_id;
	cout << "������������";
	is >> a.m_name;
	cout << "����������ɼ���";
	is >> a.m_physics;
	cout << "��������ѧ�ɼ���";
	is >> a.m_math;
	cout << "������Ӣ��ɼ���";
	is >> a.m_english;
	cout << "�������" << endl;
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