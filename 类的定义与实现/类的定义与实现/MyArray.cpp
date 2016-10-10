#include "MyArray.h"
#include "iostream"

MyArray::MyArray(int length)
{
	this->mySpace = new int[length];
	this->myLength = length;
}

//MyArray::MyArray(const MyArray& myA)
//{
//	int i = 1;
//	this->myLength = myA.myLength;
//	this->mySpace = new int[myA.myLength];
//
//	for (i = 1; i < myA.myLength; i++)
//	{
//		mySpace[i] = myA.mySpace[i];
//	}
//}

int MyArray::length()
{
	return this->myLength;
}

void MyArray::setData(int index, int data)
{
	if(mySpace[index] == NULL)
	{
		return;
	}
	mySpace[index] = (int)data;
}

int MyArray::getData(int index)
{
	return mySpace[index];
}

MyArray::~MyArray(void)
{
	delete []mySpace;
}

//жиди[]
int& MyArray::operator[](int i)
{
	return mySpace[i];
}


bool MyArray::operator!=(MyArray &a)
{
	int i = 0;
	for(i = 0; i < this->myLength; i++)
	{
		if (this->mySpace[i] != a[i])
		{
			return true;
		}
	}
	return false;
}