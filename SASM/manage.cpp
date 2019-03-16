#include"manage.h"
#include"student.h"
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
Manage::Manage() {}
void Manage::add(const Student &a) {
	stu.push_back(a);
}//����һ��ѧ����¼
int Manage::show_id(const string &id) {//ͨ��ѧ�Ų���Ȼ�󷵻ظ�ѧ������ţ���vector�е��½Ǳ꣩
	int i;
	for (i = 0; i < stu.size(); ++i) {
		if (id == stu.at(i).showid())return i;
	}
	return i;
}
int Manage::show_name(const string &name) {//ͨ����������Ȼ�󷵻ظ�ѧ������ţ���vector�е��½Ǳ꣩
	int i;
	for (i = 0; i < stu.size(); ++i) {
		if (name == stu.at(i).showname())return i;
	}
	return i;
}
void Manage::del(int &i) {//ɾ��һ��ѧ��
	for (; i + 1 < stu.size(); ++i) {
		stu.at(i) = stu.at(i + 1);
	}
	stu.pop_back();
}
vector<string> Manage::show_score(const int &a, const int &b, const int &c) {//��ѯָ�������ε���
	vector<string>name_list;
	switch (c){//�˴���c���������ǲ�ѯ��һ����Ŀ����abΪ��������С�����ֵ��
	case '1':
		for (auto i : stu) {
			if (i.showphysics() >= a && i.showphysics() <= b)name_list.push_back(i.showname());
		}//���ɼ��������䷶Χ�ڵ�ѧ����������������
		break;
	case '2':
		for (auto i : stu) {
			if (i.showmath() >= a && i.showmath() <= b)name_list.push_back(i.showname());
		}
		break;
	default:
		for (auto i : stu) {
			if (i.showenglish() >= a && i.showenglish() <= b)name_list.push_back(i.showname());
		}
		break;
	}
	return name_list;
}
float  Manage::avg(const char &choose) {//��ȡ�ܷ�ƽ��ֵ
	float sum = 0;
	for (auto i : stu) {
		sum += i.showall();
	}
	return sum / stu.size();
}
float  Manage::avg(const char &choose, const char &flag) {//��ȡ����ƽ��ֵ������flag��Ϊ��־λ
	float sum = 0;
	switch(choose) {
	case '2':
		for (auto i : stu) {
			sum += i.showphysics();
		}
		break;
	case '3':
		for (auto i : stu) {
			sum += i.showmath();
		}
		break;
	default:
		for (auto i : stu) {
			sum += i.showenglish();
		}
		break;
	}
	return sum / stu.size();//ƽ��ֵ�ڴ˴����
}
double Manage::pass_rate(const char &choose) {//���㵥�Ƽ�����
	double sum = 0;
	switch (choose) {
	case '2':
		for (auto i : stu) {
			if (i.showphysics() >= 60)++sum;
		}
		break;
	case '3':
		for (auto i : stu) {
			if (i.showmath() >= 60)++sum;
		}
		break;
	default:
		for (auto i : stu) {
			if (i.showenglish() >= 60)++sum;
		}
		break;
	}
	return sum / stu.size();
}
double Manage::standard_deviation(const char &choose) {//�����Ŀ��׼��
	double sum = 0;
	double allavg = avg(1);
	double pavg = avg(2, 1); //������ƽ��ֵ�ļ���
	double mavg = avg(3, 1);
	double eavg = avg(4, 1);
	switch (choose) {
	case '1':
		for (auto i : stu) {
			double a = (i.showall() - allavg);
			a = a * a;
			sum += a;
		}
		break;
	case '2':
		for (auto i : stu) {
			double a = (i.showphysics() - pavg);
			a = a * a;
			sum += a;
		}
		break;
	case '3':
		for (auto i : stu) {
			double a = (i.showmath() - mavg);
			a = a * a;
			sum += a;
		}
		break;
	default:
		for (auto i : stu) {
			double a = (i.showenglish() - eavg);
			a = a * a;
			sum += a;
		}
		break;
	}
	return sqrt(sum / stu.size());
}
void Manage::rank() {//�༶�ɼ�����
	for (int i = 0; i+1 < stu.size(); ++i) {
		for (int j = 0; j+1 < stu.size(); ++j) {//ʹ��Ƕ��forѭ����ð�ݱ���
			if (stu[j].showall() > stu[j + 1].showall()) {//��if-else�����ȼ�������
				Student a = stu[j];//ð�������ǰ�󽻻�
				stu[j] = stu[j + 1];
				stu[j + 1] = a;
			}
			else if (stu[j].showall() == stu[j + 1].showall() &&stu[j].showmath() > stu[j + 1].showmath()) {
				Student a = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = a;
			}
			else if (stu[j].showall() == stu[j + 1].showall() &&stu[j].showmath() == stu[j + 1].showmath() &&stu[j].showphysics() > stu[j + 1].showphysics()) {
				Student a = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = a;
			}
			else if (stu[j].showall() == stu[j + 1].showall() &&stu[j].showmath() == stu[j + 1].showmath() &&stu[j].showphysics() == stu[j + 1].showphysics() &&stu[j].showenglish() > stu[j + 1].showenglish()) {
				Student a = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = a;
			}
			else if (stu[j].showall() == stu[j + 1].showall() &&stu[j].showmath() == stu[j + 1].showmath() &&stu[j].showphysics() == stu[j + 1].showphysics() &&stu[j].showenglish() == stu[j + 1].showenglish() &&stu[j].showid() > stu[j + 1].showid()) {
				Student a = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = a;
			}
		}
	}
}
void Manage::read_file(const string &path) {//����·����ȡ�ļ�����
	stu.clear();
	int i = 1;
	Student a("0", "nill", 0, 0, 0);//����һ����ʼ��״̬ѧ��
	ifstream in(path);//��ʼ��ȡ
	if (in) {
		string line, word;
		while (getline(in, line)) {//���ж�ȡ������
			istringstream iss(line);
			while (iss >> word) {//���������ַ����ٸ��ݿո���
				switch (i % 5) {//��ֺ�������޸ĳ�ʼ��״̬��ѧ����Ϣ
				case 1:
					a.setid(word);
					break;
				case 2:
					a.setname(word);
					break;
				case 3:
					a.setmath(stoi(word));
					break;
				case 4:
					a.setphysics(stoi(word));
					break;
				default:
					a.setenglish(stoi(word));
					break;
				}
				++i;
			}
			stu.push_back(a);//һ��ѧ��������ϣ�����༶
		}
	}
	in.close();//�Ͽ�����
}
void Manage::write_file(const string &path) {//���ļ����浽ָ��·�������û���򴴽�����ļ�
	ofstream out(path);
	if (out) {//����򿪳ɹ�
		for (auto i : stu) {
			out << i.showid() << " " << i.showname() << " " << i.showmath() << " " << i.showphysics() << " " << i.showenglish() << '\n';//��ѧ�������԰���ʽд���ļ�
		}
	}
	out.close();//�Ͽ�����
}
void  Manage::blurry_rook(vector<int> &value,const int choose){//ģ����ѯ������
	int v_l = value.size();//��Ϊ���������ѧ������
	for (int i = 0; i < v_l; ++i) {
		int v_v = value.at(i);//Ϊ��i��ѧ������ֵ����������ѧ�����Ա�
		for (int j = 0; j < v_l; ++j) {
			if (choose == 1) {
				if (stu.at(v_v).showid() < stu.at(j).showid()) {
					int c = i;//�����ָ����ѧ��ʱ��������������
					value.at(i) = value.at(j);
					value.at(j) = value.at(i);
				}
			}
			if (choose == 2) {
			if (stu.at(v_v).showall() < stu.at(j).showall()) {
				int c = i;
				value.at(i) = value.at(j);
				value.at(j) = value.at(i);}
			}
			if (choose == 3) {
				if (stu.at(v_v).showmath() < stu.at(j).showmath()) {
					int c = i;
					value.at(i) = value.at(j);
					value.at(j) = value.at(i);
				}
			}
			if (choose == 4) {
				if (stu.at(v_v).showphysics() < stu.at(j).showphysics()) {
					int c = i;
					value.at(i) = value.at(j);
					value.at(j) = value.at(i);
				}
			}
			if (choose == 5) {
				if (stu.at(v_v).showenglish() < stu.at(j).showenglish()) {
					int c = i;
					value.at(i) = value.at(j);
					value.at(j) = value.at(i);
				}
			}
		}
	}
}
vector<int> Manage::Blurry(const string &key,const int choose) {//ģ����ѯ���������½Ǳ꼯
	int key_long = key.length();
	vector<int>value;
	string a;
	if (key_long) {
		for (int i = 0;i<stu.size();++i){
			a = stu.at(i).showname();
			if (a.find(key) != string::npos)//�ж��û�����Ĺؼ����Ƿ�����ѧ��������һ����
				value.push_back(i);
		}
		blurry_rook(value,choose);//�˴���������
		return value;
	}
	else return value;
}