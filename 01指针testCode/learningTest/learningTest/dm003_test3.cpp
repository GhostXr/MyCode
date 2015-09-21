#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

#define DIMSIZE(a) (sizeof(a)/sizeof(*a));

int _deleteSpace(char *allStr, char *str, char *len)
{
	int rect = 0;
	char *temp = allStr;
	char *newStr = str;
	char *strLen = len;

	int count = 0;
	int i = 0;

	if(allStr == NULL)
	{
		rect = 0;
		return rect;
	}
	
	for(i = 0; i < strlen(temp); i++)
	{
		if (!iswspace(temp[i]))
		{
			*newStr = temp[i];
			*newStr ++;
			count ++;
		}
	}
	*strLen = count;
	rect = 1;

	return rect;
}

int _findValueByKey(char *buf1, char *keyBuf, char *valeuBuf, char *valueLen)
{
	int rect = 0;
	char *buf = buf1;
	char *key = keyBuf;
	char *value = valeuBuf;
	char *len = valueLen;

	int count = 0;

	if (buf1 != NULL || keyBuf != NULL)
	{
		if (strstr(buf, key) != NULL)
		{
			while (*buf)
			{
				if (*buf == '=')
				{
					buf ++;
					rect = _deleteSpace(buf, value, len);
				}
				buf ++;
			}
		}
		else
		{
			rect = 0;
		}
	}
	else
	{
		rect = -1;
	}
	return rect;
}

int main03()
{
	int rect = 0;
	char *buf1[] = {" key1 = value2 ", "key2=value3"," key3=  '' "," key4 =''"," key5 = valusedge5 "};
	char *keyBuf = "key5";
	char valueBuf[50] = {0};
	char valueLen = 0;
	int i = 0;

	int size = DIMSIZE(buf1);

	for (i = 0; i < size; i++)
	{
		rect = _findValueByKey(buf1[i], keyBuf, valueBuf, &valueLen);
		if (rect == 1)
		{
			printf("value str is: %s\n", valueBuf);
			printf("value Len is: %d\n", valueLen);
		}
		else if (rect == -1)
		{
			printf("func _findValueByKey is error: %d", rect);
		}

	}
	system("pause");
	return 0;
}