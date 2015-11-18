#include "iostream"
#include <time.h> 
#include <stdio.h> 

using namespace std;   

int quickSort(int array[], int l, int r)
{
	if (array == NULL)
	{
		return -1;
	}
	if (l < r)
	{
		int i = l, j = r, temp = array[l];
		while (i < j)
		{
			while(i < j && array[j] > temp)
			{
				j --;
			}
			if (i < j)
				array[i++] = array[j];
			
			while(i < j && array[i] < temp)
			{
				i ++;
			}
			if (i < j)
				array[j--] = array[i];
		}
		array[i] = temp;
		quickSort(array, l, i-1);
		quickSort(array, i+1, r);

	}
	return 0;
}

int selectedSort(int array[], int length)
{
	int i, j, temp;
	for (i = 0; i < length; i++)
	{
		for (j = i+1; j < length; j ++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return 0;
}

int bubbleSort(int array[], int length)
{
	int i, j, temp;
	for (i = 0; i < length-1; i++)
	{
		for (j = 0; j < length-1; j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return 0;
}

int main()
{
	int array[] = {23, 46, 7, 9, 39, 94, 83, 39, 92, 11};
	int length = sizeof(array)/sizeof(int);
	int i, rect;
	cout<<"sort before"<<endl;
	for(i = 0; i < length; i++)
	{
		cout<<"array["<<i<<"] == "<<array[i]<<endl;
	}
	
	/*rect = quickSort(array, 0, length-1);
	if (rect != 0)
	{
		cout<<"quickSort func error"<<endl;
		return 0;
	}*/
	
	/*cout<<"quick sort ended"<<endl;
	for(i = 0; i < length; i++)
	{
		cout<<"array["<<i<<"] == "<<array[i]<<endl;
	}*/

	//selectedSort(array, length);

	bubbleSort(array, length);
	cout<<"bubble sort ended"<<endl;
	for(i = 0; i < length; i++)
	{
		cout<<"array["<<i<<"] == "<<array[i]<<endl;
	}


	system("pause");
	return 0;
}