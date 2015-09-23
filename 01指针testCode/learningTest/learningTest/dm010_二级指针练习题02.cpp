#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

void reverse(char *str, int strLen)
{
	char *temp1 = str;
	char *temp2 = str + strLen - 1;
	if (str == NULL)
	{
		return ;
	}
}

int findCount(char *myStr, char *buf, char *newStr, int *count)
{
	char *str1 = myStr, *str2 = myStr;
	int num = 0;
	int bufLen = 0;
	bufLen = strlen(buf);

	if (myStr == NULL || buf == NULL) 
	{
		return -1;
	}
	do
	{
		str1 = strstr(str1, buf);
		if (str1 != NULL)
		{
			if (str1 - str2 >= 0)
			{
				strncpy(newStr, str2, str1 - str2);
				reverse(str1, bufLen);
				(*count) ++;
				str1 = str1 + bufLen;
			}

		}
		else
		{
			break;
		}
	} while (*str1 != '\0');

	return 0;
}

int main010()
{
	int i = 0;
	char *myStr = "abcd11111abcdggggggabcd33333abcdoooooabcd";
	char *buf = "abcd";
	int count = 0, rect = 0;
	int length = strlen(myStr);
	char newStr[100] = {};

	rect = findCount(myStr, buf, newStr, &count);

	if (rect != 0)
	{
		printf("function findCount is error\n");
		return 0;
	}

	printf("%s \n", newStr);
	printf("array count is %d ", count);

	system("pause");
	return 0;
}