#include <iostream>

#include "SeqList.h"
#include "LinkList.h"
#include "CircleList.h"

using namespace std;

typedef struct Teacher
{
	int age;
	char name[4];
}Tech;

void test01()
{
	
	SeqList* list = NULL;
	list = seqListCreate(20);
	if(list == NULL)
	{
		cout<<"seqListCreate is error"<<endl;
		return;
	}

	Tech t1, t2, t3, t4;
	t1.age = 34;
	t2.age = 44;
	t3.age = 64;
	t4.age = 35;
	seqListInsert(list, &t1, 1);
	seqListInsert(list, &t2, 1);
	seqListInsert(list, &t3, 1);
	seqListInsert(list, &t4, 1);

	for(int i = 0; i <seqListLength(list); i++)
	{
		Tech* temp = (Tech*)seqListGet(list, i);
		cout<<temp->age<<" ";
	}
	cout<<endl;

	while (seqListLength(list) > 0)
	{
		seqListDelete(list, 0);
	}

	for(int i = 0; i <seqListLength(list); i++)
	{
		Tech* temp = (Tech*)seqListGet(list, i);
		cout<<temp->age<<" ";
	}
}

typedef struct Student
{
	LinkListNode node;
	int age;
}Student;

void test02()
{
	LinkList* list = NULL;
	list = linkListCreate();
	if(list == NULL)
	{
		cout<<"linkListCreate is error"<<endl;
		return;
	}

	Student t1, t2, t3, t4;
	t1.age = 59;
	t2.age = 44;
	t3.age = 64;
	t4.age = 35;
	linkListInsert(list, (LinkListNode*)&t1, 0);
	linkListInsert(list, (LinkListNode*)&t2, 2);
	linkListInsert(list, (LinkListNode*)&t3, 3);
	linkListInsert(list, (LinkListNode*)&t4, 4);

	for(int i = 0; i <linkListLength(list); i++)
	{
		Student* temp = (Student*)linkListGet(list, i);
		cout<<temp->age<<" ";
	}
	cout<<endl;

	
	Student* node = (Student*)linkListDelete(list, 2);
	cout<<node->age<<endl;
	/*while (linkListLength(list) > 0)
	{
		Student* node = (Student*)linkListDelete(list, 0);
		cout<<node->age<<endl;
		node = NULL;
	}
	*/


	for(int i = 0; i <linkListLength(list); i++)
	{
		Student* temp = (Student*)linkListGet(list, i);
		cout<<temp->age<<" ";
	}
}

typedef struct Value
{
	LinkListNode node;
	int v;
}Value;

void test03()
{
	CircleList* list = NULL;
	list = circleListCreate();
	if(list == NULL)
	{
		cout<<"linkListCreate is error"<<endl;
		return;
	}

	Value t1, t2, t3, t4, t5, t6, t7, t8;
	t1.v = 1;
	t2.v = 2;
	t3.v = 3;
	t4.v = 4;
	t5.v = 5;
	t6.v = 6;
	t7.v = 7;
	t8.v = 8;
	circleListInsert(list, (CircleListNode*)&t1, 0);
	circleListInsert(list, (CircleListNode*)&t2, 0);
	circleListInsert(list, (CircleListNode*)&t3, 0);
	circleListInsert(list, (CircleListNode*)&t4, 0);
	circleListInsert(list, (CircleListNode*)&t5, 0);
	circleListInsert(list, (CircleListNode*)&t6, 0);
	circleListInsert(list, (CircleListNode*)&t7, 0);
	circleListInsert(list, (CircleListNode*)&t8, 0);

	
	for(int i = 0; i < circleListLength(list); i++)
	{
		Value* temp = (Value*)circleListGet(list, i);
		cout<<temp->v<<" ";
	}
	cout<<endl;
}

void main()
{
	//test01();  //顺序存储线性表
	
	//test02();  //链式存储线性表
	
	//test03();  //循环链表

	//test04();   //双向链表

	system("pause");
	return;
}