#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

void _findValueByKey(char *buf)
{
	//char *buf = buf1;
	//char *newstr = newstr1;

	int count = 0;

	if (buf == NULL )
	{
		return;
	}
	if (*buf == '\0' )
	{
		return;
	}
	_findValueByKey(buf++);
	printf("buf is: %s\n", *buf);
}

int main04()
{
	int rect = 0;
	char buf[] = "asdgsdghd";
	char valueBuf[50] = {0};
	_findValueByKey(buf);
	//printf("value str is: %s\n", valueBuf);
	
	system("pause");
	return 0;
}