#include <iostream>
#include "stack"
using namespace std;



void test1()
{
	stack<int> st;
	for(int i = 0; i <10; i ++)
	{
		st.push(i);
	}

	cout<<"Õ»µÄ´óÐ¡£º"<<st.size()<<endl;

	while( !st.empty())
	{
		int temp = st.top();
		cout <<"temp = "<<temp<<endl;
		st.pop();
	}
}

class Teacher
{
public:
	void printT()
	{
		cout<<age<<endl;
	}
public:
	int age;
	char name[32];
};

void test2()
{
	Teacher t1, t2, t3;
	t1.age = 32;
	t2.age = 23;
	t3.age = 26;

	stack<Teacher> st;
	st.push(t1);
	st.push(t2);
	st.push(t3);

	while(! st.empty())
	{
		Teacher temp = st.top();
		temp.printT();
		st.pop();
	}
}

void test3()
{
	
	Teacher t1, t2, t3;
	t1.age = 32;
	t2.age = 23;
	t3.age = 26;

	stack<Teacher*> st;
	st.push(&t1);
	st.push(&t2);
	st.push(&t3);
	
	while(! st.empty())
	{
		Teacher *temp = st.top();
		temp->printT();
		st.pop();
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