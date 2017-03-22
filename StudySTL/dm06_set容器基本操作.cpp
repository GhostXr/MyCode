#include <iostream>
#include "set"
using namespace std;

//������ �����
//set��һ�����ϣ�Ԫ��Ψһ�����ܰ���[]��ʽ����Ԫ��, 
//�Զ�����Ĭ�ϴ�С����
void test1()
{
	set<int> st;
	cout<<"��С��"<<st.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		st.insert(temp);
	}
	st.insert(100);
	st.insert(100);
	st.insert(100);

	for(set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	while(! st.empty())
	{
		set<int>::iterator it = st.begin();
		cout<<*it<<" ";
		st.erase(st.begin());
	}
}

void test2()
{
	/*set<int> st1;
	set<int, less<int>> st2;  //��С����
	set<int, greater<int>> st3;  //�Ӵ�С
	cout<<"��С��"<<st1.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		st1.insert(temp);
	}
	
	for(set<int>::iterator it = st1.begin(); it != st1.end(); it++)
	{
		cout<<*it<<" ";
	}
	*/
}

class Teacher
{
public:
	Teacher(int age, char* name)
	{
		this->age = age;
		strcmp(this->name, name);
	}
	void printT()
	{
		cout<<age<<endl;
	}
public:
	int age;
	char name[32];
};

//�º�������
struct FuncSort
{
	bool operator() (Teacher t1, Teacher t2)
	{
		cout<<t1.age<<" ";
		cout<<endl;
		cout<<t2.age<<" ";
		return t1.age < t2.age;
	}
};

void test3()
{
	Teacher t1(22, "hao"), t2(34, "hua"), t3(18, "asdv"), t4(45, "beer");
	set<Teacher, FuncSort> st;
	st.insert(t1);
	st.insert(t2);
	st.insert(t3);
	st.insert(t4);
	
	for(set<Teacher>::iterator it = st.begin(); it != st.end(); it++)
	{
		Teacher temp = *it;
		cout<<temp.age<<" ";
	}
}

void main()
{
	//test1();
	//test2();
	test3();

	system("pause");
	return;
}