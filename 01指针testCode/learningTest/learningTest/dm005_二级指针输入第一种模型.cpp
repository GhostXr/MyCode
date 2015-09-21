#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

void sortMyArray01(char **myArray, int num)
{
	int i = 0, j = 0;
	char *temp = NULL;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				temp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
}

int main06()
{
	int i = 0;
	char *array[] = {"aaaaa","dddd","wwww","11111",};
	int num = 0;
	int num2 = 0;

	num = sizeof(array)/sizeof(array[0]);

	sortMyArray01(array, num);
	for (i = 0; i < num; i++)
	{
		printf(" %s", array[i]);
	}

	system("pause");
	return 0;
}