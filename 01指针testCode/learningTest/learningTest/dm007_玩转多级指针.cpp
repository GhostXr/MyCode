#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

int **getMeme02(char ***array, int num)
{
	int i = 0;
	char **p = NULL;
	p = (char **)malloc(sizeof(char *) * num);

	for (i = 0; i < num; i ++)
	{
		p[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p[i], "%d%d%d", i, i, i);
	}
	*array = p;
	return 0;
}

int main07()
{
	int i = 0;
	char **array = NULL;
	int num = 4;

	getMeme02(&array, num);

	for (i = 0; i < num; i++)
	{
		printf(" %s", array[i]);
	}

	system("pause");
	return 0;
}