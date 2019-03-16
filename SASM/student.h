#ifndef HEADER_STUDENT
#define HEADER_STUDENT
#include <iostream>
#include <string>
using namespace std;
class Student {
	string m_id; //ѧ��ѧ��
	string m_name; //ѧ������
	short int m_math;  //ѧ���ɼ�����ͬ
	short int m_physics;
	short int m_english;
public:
	Student(string id = 0, string name = "nill", short int math = 0, short int physics = 0, short int english = 0) :
		m_id(id), m_name(name), m_math(math), m_physics(physics), m_english(english){}
	~Student() {}

	string showid() const;//��ȡһ��ѧ����ѧ�ţ���ͬ
	string showname() const;
	short int showmath() const;
	short int showenglish() const;
	short int showphysics() const;
	short int showall() const;

	void setid(const string &id);//�޸�һ��ѧ����ѧ�ţ���ͬ
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
