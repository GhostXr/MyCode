#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

void sortMyArray013(char **myArray, int num)
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

char** getMemo013(int num)
{
	int i = 0;
	char **array = NULL;
	array = (char **)malloc(sizeof(char *) * num);

	if (array == NULL)
	{
		return 0;
	}

	for(i = 0; i < num; i++)
	{
		array[i] = (char *)malloc(128);
	}

	return array;
}

void freeArray(char ***array, int num)
{
	int i = 0;
	char **temp = *array;
	if (array == NULL)
	{
		return;
	}
	for(i = 0; i < num; i ++)
	{
		if (temp[i] != NULL)
		{
			free(temp[i]);
		}
	}
	free(temp);
	*array = NULL;
}

int mergerStr(char *array1[], int num1, char array2[10][20], int num2, char ***array3)
{
	if (array1 == NULL || array2 == NULL)
	{
		return -1;
	}
	char ** buf1 = array1;
	char ** buf3 = NULL;
	int tempLen = 0;

	buf3 = (char **)malloc(sizeof(char *) * (num1 + num2));

	//memset(buf3, 0, sizeof(char *) * (num1 + num2));

	if (buf3 == NULL)
	{
		return -2;
	}

	int i = 0, j = 0;

	for (i = 0; i < num1; i++)
	{
		if(array1[i] != NULL)
		{
			tempLen = strlen(array1[i]) + 1;
			buf3[j] = (char *)malloc(tempLen * sizeof(char));
			strcpy(buf3[j], array1[i]);
			j ++;
		}
	}

	for (i = 0; i < num2; i++)
	{
		if(array2[i] != NULL)
		{
			tempLen = strlen(array2[i]) + 1;
			buf3[j] = (char *)malloc(tempLen * sizeof(char));
			strcpy(buf3[j], array2[i]);
			j ++;
		}
	}
	sortMyArray013(buf3, num1 + num2);

	*array3 = buf3;
	return 0;
}

int main()
{
	int i = 0, rect = 0;
	char *array1[] = {"aaaaa","dddd","wwww","11111",};
	char array2[10][20] = {"22222","66666","55555","333333",};
	char **array3 = NULL;

	int num = 4;
	int num2 = 4;

	//num = sizeof(array1)/sizeof(array1[0]);
	//num2 = sizeof(array2);

	rect = mergerStr(array1, num, array2, num2, &array3);
	if (rect != 0)
	{
		printf("func mergerStr is error: %d", rect);
		return 0;
	}

	for (i = 0; i < (num + num2); i++)
	{
		printf(" %s \n", array3[i]);
	}
	
	freeArray(&array3, num + num2);

	system("pause");
	return 0;
}