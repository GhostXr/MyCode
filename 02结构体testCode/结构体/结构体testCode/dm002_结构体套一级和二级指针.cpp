#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[128];
	char *alistName;
	char **studentName;
	int age;
	int id;
};

Teacher *createTeacher01(int num)
{
	Teacher *temp = NULL;
	int i = 0, j = 0;

	if (num == NULL)
	{
		return 0;
	}
	temp = (Teacher *)malloc(sizeof(Teacher) * num);
	memset(temp, 0, sizeof(Teacher) * num);
	
	for (i = 0; i < num; i++)
	{
		temp[i].alistName = (char *)malloc(120);
		
		char **student = temp[i].studentName;
		if (student == NULL)
		{
			student = (char **)malloc(sizeof(char*) * num);
			for (j = 0; j < num; j++)
			{
				student[j] = (char *)malloc(64);
			}
		}
	}
	return temp;
}

int createTeacher02(Teacher **teacher, int num)
{
	Teacher *temp = NULL;
	int rect = 0, i = 0, j = 0;

	if (num == NULL)
	{
		return -1;
	}
	temp = (Teacher *)malloc(sizeof(Teacher) * num);
	memset(temp, 0, sizeof(Teacher) * num);
	
	for (i = 0; i < num; i++)
	{
		temp[i].alistName = (char *)malloc(120);
		
		char **student = NULL;
		if (student == NULL)
		{
			student = (char **)malloc(sizeof(char *) * num);

			for (j = 0; j < num; j++)
			{
				student[j] = (char *)malloc(120);
			}
			temp[i].studentName = student;
		}
	}
	*teacher = temp;
	return rect;
}

void freeTeacher(Teacher **teacher, int num)
{
	Teacher *temp = *teacher;
	int i = 0, j = 0;
	if (teacher == NULL)
	{
		return;
	}
	
	for (i = 0; i < num; i++)
	{
		if (temp[i].alistName != NULL)
		{
			free(temp[i].alistName);
		}

		if (temp[i].studentName != NULL)
		{
			char **student = temp[i].studentName;
			for (j = 0; j < num; j++)
			{
				if (student[j] != NULL)
					free(student[j]);
			}
			free(student);
			temp[i].studentName = NULL;
		}
	}
	free(temp);
	*teacher = NULL;
}

int main002()
{
	Teacher *teacher;
	int rect = 0, i = 0, j = 0, num = 1;
	//teacher = createTeacher01(num);
	rect = createTeacher02(&teacher, num);
	if (rect != 0)
	{
		printf("func createTeacher02 is error: %d", rect);
	}

	for (i = 0; i < num; i++)
	{
		printf("\n please enter teacher name:");
		scanf("%s", teacher[i].name);

		for(j = 0; j < num; j++)
		{
			printf("\n please enter student name %d:", j);
			scanf("%s", teacher[i].studentName[j]);
		}
	}
	
	for (i = 0; i < num; i++)
	{
		for(j = 0; j < num; j++)
		{
			printf("teacher[%d].student == %s", i, teacher[i].studentName[j]);
		}
	}

	freeTeacher(&teacher, num);

	printf("hello... \n");
	system("pause");
	return 0;
}