#include <iostream>
#include "queue"
using namespace std;

void test1()
{
	queue<int> q;
	for(int i = 0; i < 10; i++)
	{
		q.push(i);
	}

	cout<<"头部："<<q.front()<<endl;
	cout<<"尾部："<<q.back()<<endl;
	cout<<"大小："<<q.size()<<endl;


	while(! q.empty())
	{
		int temp = q.front();
		cout<< temp <<" ";
		q.pop();
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

	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);

	while(! q.empty())
	{
		Teacher temp = q.front();
		temp.printT();
		q.pop();
	}
}

void test3()
{
	
	Teacher t1, t2, t3;
	t1.age = 32;
	t2.age = 23;
	t3.age = 26;

	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while(! q.empty())
	{
		Teacher *temp = q.front();
		temp->printT();
		q.pop();
	}
}

void main()
{
	//test1();
	test2();

	system("pause");
	return;
}