#include"manage.h"
#include"student.h"
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
Manage::Manage() {}
void Manage::add(const Student &a) {
	stu.push_back(a);
}//增加一个学生记录
int Manage::show_id(const string &id) {//通过学号查找然后返回该学生的序号（在vector中的下角标）
	int i;
	for (i = 0; i < stu.size(); ++i) {
		if (id == stu.at(i).showid())return i;
	}
	return i;
}
int Manage::show_name(const string &name) {//通过姓名查找然后返回该学生的序号（在vector中的下角标）
	int i;
	for (i = 0; i < stu.size(); ++i) {
		if (name == stu.at(i).showname())return i;
	}
	return i;
}
void Manage::del(int &i) {//删除一个学生
	for (; i + 1 < stu.size(); ++i) {
		stu.at(i) = stu.at(i + 1);
	}
	stu.pop_back();
}
vector<string> Manage::show_score(const int &a, const int &b, const int &c) {//查询指定分数段的人
	vector<string>name_list;
	switch (c){//此处的c用来决定是查询哪一个科目，而ab为分数的最小和最大值；
	case '1':
		for (auto i : stu) {
			if (i.showphysics() >= a && i.showphysics() <= b)name_list.push_back(i.showname());
		}//将成绩属于区间范围内的学生姓名加入容器内
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
float  Manage::avg(const char &choose) {//求取总分平均值
	float sum = 0;
	for (auto i : stu) {
		sum += i.showall();
	}
	return sum / stu.size();
}
float  Manage::avg(const char &choose, const char &flag) {//求取单科平均值，其中flag作为标志位
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
	return sum / stu.size();//平均值在此处完成
}
double Manage::pass_rate(const char &choose) {//计算单科及格率
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
double Manage::standard_deviation(const char &choose) {//计算科目标准差
	double sum = 0;
	double allavg = avg(1);
	double pavg = avg(2, 1); //调用了平均值的计算
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
void Manage::rank() {//班级成绩排序
	for (int i = 0; i+1 < stu.size(); ++i) {
		for (int j = 0; j+1 < stu.size(); ++j) {//使用嵌套for循环做冒泡遍历
			if (stu[j].showall() > stu[j + 1].showall()) {//用if-else做优先级的排序
				Student a = stu[j];//冒泡排序的前后交换
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
void Manage::read_file(const string &path) {//根据路径读取文件内容
	stu.clear();
	int i = 1;
	Student a("0", "nill", 0, 0, 0);//创建一个初始化状态学生
	ifstream in(path);//开始读取
	if (in) {
		string line, word;
		while (getline(in, line)) {//按行读取数据流
			istringstream iss(line);
			while (iss >> word) {//将读到的字符串再根据空格拆分
				switch (i % 5) {//拆分后的数据修改初始化状态的学生信息
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
			stu.push_back(a);//一个学生更新完毕，导入班级
		}
	}
	in.close();//断开连接
}
void Manage::write_file(const string &path) {//将文件保存到指定路径，如果没有则创建这个文件
	ofstream out(path);
	if (out) {//如果打开成功
		for (auto i : stu) {
			out << i.showid() << " " << i.showname() << " " << i.showmath() << " " << i.showphysics() << " " << i.showenglish() << '\n';//将学生的属性按格式写入文件
		}
	}
	out.close();//断开连接
}
void  Manage::blurry_rook(vector<int> &value,const int choose){//模糊查询后排序
	int v_l = value.size();//次为符合情况的学生个数
	for (int i = 0; i < v_l; ++i) {
		int v_v = value.at(i);//为第i个学生的数值，与其后面的学生做对比
		for (int j = 0; j < v_l; ++j) {
			if (choose == 1) {
				if (stu.at(v_v).showid() < stu.at(j).showid()) {
					int c = i;//当出现更大的学生时交换两个的内容
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
vector<int> Manage::Blurry(const string &key,const int choose) {//模糊查询并返回其下角标集
	int key_long = key.length();
	vector<int>value;
	string a;
	if (key_long) {
		for (int i = 0;i<stu.size();++i){
			a = stu.at(i).showname();
			if (a.find(key) != string::npos)//判断用户输入的关键词是否属于学生姓名的一部分
				value.push_back(i);
		}
		blurry_rook(value,choose);//此处调用排序
		return value;
	}
	else return value;
}