#include <iostream>

#include "vector"
#include "algorithm"

using namespace std;

void setVector1()
{
	vector<int> v1;   //容器
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);

	//迭代器 it（指针）
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<*it<<endl;
	}

	//算法
	int num = count(v1.begin(), v1.end(),3);
	cout<<"num == "<<num<<endl;
}

class Teacher
{
public:
	int age;
	char name;
public:
	void printT()
	{
		cout<<"age == "<<age<<endl;
	}
private:

};

void setVector2()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 23;
	t3.age = 34;

	vector<Teacher> v1;   //容器
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//迭代器 it（指针）
	for(vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<it->age<<endl;
	}

}

void setVector3()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 23;
	t3.age = 34;
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	vector<Teacher*> v1;   //容器
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//迭代器 it（指针）
	for(vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<(*it)->age<<endl;
	}

}


void main()
{
	//基础数据类型
	//setVector1();

	//类元素
	//setVector2();

	//指针
	setVector3();

	cout<<"Hello Word!"<<endl;

	system("pause");
	return;
}