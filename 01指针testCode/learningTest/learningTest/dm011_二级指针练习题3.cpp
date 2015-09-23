#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

char **getMemo011(char **p, int num)
{
	int i = 0;
	char **pTemp = p;
	pTemp = (char **)malloc(sizeof(char *) * num);
	for (i = 0; i < num; i ++)
	{
		pTemp[i] = (char *)malloc(sizeof(char) * num);
	}
	return pTemp;
}

void freeMemo011(char **p, int num)
{
	int i = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		free(p[i]);
	}
	free(p);
}

int splitString011(char *myStr, const char splitStr, char ***myArray, int *count)
{
	char *str1 = myStr, *str2 = myStr;
	char split = splitStr;
	char **array = NULL;
	int num = 0;


	if (myStr == NULL || splitStr == NULL) 
	{
		return -1;
	}
	
	array = getMemo011(array, 10);

	do
	{
		str1 = strchr(str1, splitStr);
		if (str1 != NULL)
		{
			if (str1 - str2 > 0)
			{
				strncpy(array[*count], str2, (str1 - str2));
				array[*count][str1 - str2] = '\0';
				(*count) ++;
				str1 = str2 = str1 + 1;
			}
		}
		else
		{
			break;
		}
	}while(*str1 != '\0');

	*myArray = array;

	return 0;
}

int main011()
{
	int i = 0;
	char *myStr = "abcdooooooabcb111111abcb55555abcb";
	char splitStr = 'abcd';
	int count = 0, rect = 0;
	char **newArray = NULL  ;

	rect = splitString011(myStr, splitStr, &newArray, &count);

	if (rect != 0)
	{
		printf("function splitString is error\n");
		return 0;
	}

	for (i = 0; i < count; i ++)
	{
		printf("%s \n", newArray[i]);
	}
	printf("array count is %d ", count);

	freeMemo011(newArray, 10);

	system("pause");
	return 0;
}