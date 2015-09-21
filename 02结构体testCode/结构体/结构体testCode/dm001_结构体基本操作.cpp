#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

//1
struct Teacher
{
	char name[32];
	int id;
	char sex[12];
};

//2
typedef struct Teacher2
{
	char name[32];
	int id;
	char sex[12];
};

//3 定义类型同时定义变量
struct Teacher3
{
	char name[32];
	int id;
	char sex[12];
}t3, t4;

//4 定义匿名类型 
struct 
{
	char name[32];
	int id;
	char sex[12];
}t5, t6;


//结构体初始化
struct Teacher4
{
	char name[32];
	int id;
	char sex[12];
}t7 = {"bbb", 23, "女"};

struct 
{
	char name[32];
	int id;
	char sex[12];
}t8 = {"cccc", 45, "男"};

int main01()
{
	struct Teacher t1 = {"aaaa", 001, "男"};

	Teacher2 t2;

	t3;
	t4;

	t5;
	t6;

	printf("hello... \n");
	system("pause");
	return 0;
}

int copyStruct(Teacher to, Teacher from)
{
	to = from;
}


int copyStruct002(Teacher *to, Teacher *from)
{
	*to = *from;
}


int main()
{
	struct Teacher t1 = {"aaaa", 001, "男"};

	Teacher t2;
	Teacher t3;

	t2 = t1;

	printf("t2.name %s\n", t2.name);

	copyStruct(t3, t1);

	printf("hello... \n");
	system("pause");
	return 0;
}