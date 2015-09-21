#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

int deleteSpaceStr(char *p, char *newStr)
{
	int rect = 0;
	char *oldStr = p;
	char *temp = newStr;
	int count = 0;


	if (p != NULL || newStr != NULL)
	{
		while (*oldStr != '\0')
		{
			if (!iswspace(*oldStr))
			{
				*temp = *oldStr;
				temp++;
				count++;
			}
			oldStr++;

		}
		*temp = '\0';
	}
	else
	{
		return rect;
	}
	return rect;
}

int main01()
{
	int rect = 0;
	char *p = "asd32dge";
	char newStr[sizeof(*p)];
	rect = deleteSpaceStr(p, newStr);
	if (rect != 0)
	{
		printf("func deleteSpaceStr is error: %d", rect);
		return rect;
	}

	//printf("*p is: %c\n", *p);
	//printf("*p++ is: %d\n", *p++);
	//printf("*(p++) is: %c\n", *(p++));
	//printf("p++ is: %d\n", p++);
	//printf("(*p)++ is: %c\n", (*p)++);
	system("pause");
	return 0;
}