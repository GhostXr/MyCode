#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

int splitStr(char *myStr, char array[20][20], int *num)
{
	int i = 0, j = 0;
	char *temp = myStr;
	char *str = myStr;
	int count = strlen(temp);
	do
	{
		temp = strchr(temp, ',');
		if (temp != NULL)
		{
			if(temp - str > 0)
			{
				strncpy(array[j], str, temp - str);
				j ++;
				array[j][temp - str] = '\0';
				str = temp = temp + 1;
			}
		}
		else
		{
			break;
		}
	}while(*temp != '\0');

	*num = j;
	return 0;
}

int main008()
{
	int i = 0;
	char *myStr = "absaga,asgsaedbh,swargae,asgrh,srtjhtdry,seh,asdrh,";
	int num = 0;
	char array[20][20] = {};

	splitStr(myStr, array, &num);

	for (i = 0; i < num; i++)
	{
		printf(" %s \n", array[i]);
	}
	printf("array count is %d", num);

	system("pause");
	return 0;
}