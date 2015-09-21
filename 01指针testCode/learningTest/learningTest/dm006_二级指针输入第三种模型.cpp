#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

void sortMyArray03(char **myArray, int num)
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

char **getMeme01(int num)
{
	int i = 0;
	char **p = NULL;
	p = (char **)malloc(sizeof(char *) * num);

	for (i = 0; i < num; i ++)
	{
		p[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p[i], "%d%d%d", i, i, i);
	}
	return p;
}

int free_MyArray(char **array, int num)
{
	int i = 0;
	if (array == NULL)
	{
		return 0;
	}
	for(i = 0; i < num; i++)
	{
		free(array[i]);
	}
	free(array);

	return 0;
}

int main006()
{
	int i = 0;
	char **array = NULL;
	int num = 4;

	array = getMeme01(num);

	sortMyArray03(array, num);
	for (i = 0; i < num; i++)
	{
		printf(" %s", array[i]);
	}

	free_MyArray(array, num);

	system("pause");
	return 0;
}