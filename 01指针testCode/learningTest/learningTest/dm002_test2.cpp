#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

int chooseStr(char *str, char *oddStr, char *evenStr)
{
	int rect = 0;
	int i = 0;
	char *allStr = str;
	char *odd = oddStr;
	char *even = evenStr;


	if (allStr != NULL)
	{
		for (i = 0; i < strlen(allStr); i++)
		{
			if ((i+1) % 2 == 0)
			{
				*odd = allStr[i];
				odd ++;
			}else
			{
				*even = allStr[i];
				even ++;
			}
		}
		*odd = '\0';
		*even = '\0';
	}
	else
	{
		return rect;
	}
	return rect;
}

int main02()
{
	int rect = 0;
	char allStr[100] = "a1s2d3d4g5e";
	char oddStr[50] = {0};
	char evenStr[50] = {0};
	rect = chooseStr(allStr, oddStr, evenStr);
	if (rect != 0)
	{
		printf("func chooseStr is error: %d", rect);
		return rect;
	}

	printf("oddStr is: %s\n", oddStr);
	printf("evenStr is: %s\n", evenStr);
	system("pause");
	return 0;
}