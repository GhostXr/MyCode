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

//3 ��������ͬʱ�������
struct Teacher3
{
	char name[32];
	int id;
	char sex[12];
}t3, t4;

//4 ������������ 
struct 
{
	char name[32];
	int id;
	char sex[12];
}t5, t6;


//�ṹ���ʼ��
struct Teacher4
{
	char name[32];
	int id;
	char sex[12];
}t7 = {"bbb", 23, "Ů"};

struct 
{
	char name[32];
	int id;
	char sex[12];
}t8 = {"cccc", 45, "��"};

int main01()
{
	struct Teacher t1 = {"aaaa", 001, "��"};

	Teacher2 t2;

	t3;
	t4;

	t5;
	t6;

	printf("hello... \n");
	system("pause");
	return 0;
}

void copyStruct(Teacher to, Teacher from)
{
	to = from;
	return 0;
}


int copyStruct002(Teacher *to, Teacher *from)
{
	*to = *from;
	return 0;
}


int main001()
{
	struct Teacher t1 = {"aaaa", 001, "��"};

<<<<<<< Updated upstream
	/*Teacher t2;
	Teacher t3;
=======
	Teacher t2;
	//Teacher t3 = {0};
>>>>>>> Stashed changes

	t2 = t1;
*/
	//printf("t2.name %s\n", t2.name);

<<<<<<< Updated upstream
=======
	printf("t2.name %s\n", t2.name);

>>>>>>> Stashed changes
	//copyStruct(t3, t1);

	printf("hello... \n");
	system("pause");
	return 0;
}