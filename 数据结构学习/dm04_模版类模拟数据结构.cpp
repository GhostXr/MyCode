
#include <iostream>
#include "SeqLink.h"

using namespace std;

struct Teacher
{
	int age;
	char name[64];
};

void test01()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 34;
	t3.age = 41;

	SeqLink<Teacher> list(10);

	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	for(int i = 0; i < 3; i++)
	{
		Teacher temp;
		list.getNode(temp, i);
		cout<<temp.age<<endl;
	}
	
	while(list.getLength() > 0)
	{
		list.deleteNode(0);
	}
}

void main()
{
	test01();

	system("pause");
	return;
}