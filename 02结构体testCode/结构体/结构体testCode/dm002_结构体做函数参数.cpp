#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[32];
	int id;
	int age;
};



int createTeacher(Teacher **tea, int num)
{
	Teacher *temp = NULL;
	int i = 0;
	if (num == 0)
	{
		return -1;
	}
	temp = (Teacher *)malloc(sizeof(Teacher) * num);

	for (i = 0; i < num; i++)
	{
		printf("\n please enter a age: ");
		scanf("%d", &temp[i].age);
	}

	if (temp == NULL)
	{
		return -2;
	}
	*tea = temp;
	return 0;
}

void freeTeacher(Teacher **tea)
{
	Teacher *temp = *tea;
	if (tea != NULL)
	{
		free(temp);
		*tea = NULL;
	}
}

int main()
{
	Teacher *teacher = NULL;
	int i, rect, num = 5;

	rect = createTeacher(&teacher, num);

	if (rect != 0)
	{
		printf("func createTeacher() is error:%d \n", rect);
		return 0;
	}

	for (i = 0; i < num; i++)
	{
		printf("teacher.age = %d \n", teacher[i].age);
	}

	freeTeacher(&teacher);

	printf("hello... \n");
	system("pause");
	return 0;
}