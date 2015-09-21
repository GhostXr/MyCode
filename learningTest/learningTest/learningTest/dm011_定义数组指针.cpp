#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int main()
{
	//先定义类型，通过类型定义变量
	typedef int(MyArrayType)[5];
	MyArrayType array;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		array[i] = i + 1;
	}

	MyArrayType *myArray = &array;

	for(i = 0; i < 10; i++)
	{
		printf("array[%d] = %d \n", i, (*myArray)[i]);
	}

	typedef int(*MyArrayType2)[5];
	MyArrayType2 array2;
	int b[5];
	array2 = &b;

	//定义数组指针变量

	int (*myArray2)[5];
	int c[5];

	myArray2 = &c;
	
	printf("hello....");
	system("pause");
	return 0;
}