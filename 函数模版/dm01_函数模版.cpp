#include <iostream>

using namespace std;

template <typename T, typename T2>
int mySort(T *array, T2 size)
{
	T temp;

	if (array == NULL)
	{
		return -1;
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return 0;
}

template <typename T, typename T2>
int myPrint(T *array, T2 size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<"array[i] == "<<array[i]<<endl;
	}
	return 0;
}

void main()
{
	//int 类型
	/*{
		int array[] = {11, 22, 33, 44, 5,55 ,66, 77};

		int size = sizeof(array)/sizeof(*array);

		int a = mySort<int>(array, size);
	
		if (a != -1)
		{
			myPrint<int>(array, size);
		}
	}*/
	
	//char 类型
	{
		char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

		int size = sizeof(array)/sizeof(*array);

		int a = mySort<char, int>(array, size);
	
		if (a != -1)
		{
			myPrint<char, int>(array, size);
		}
	}

	//cout<<"hello...."<<endl;
	system("pause");
	return;
}