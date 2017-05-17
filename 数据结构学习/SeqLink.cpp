#include "SeqLink.h"

template <typename T>
SeqLink<T>::SeqLink(int num)
{
	T *pArray;
	pArray = new T[capacity];
	capacity = num;
	length = 0;
}

template <typename T>
SeqLink<T>::~SeqLink(void)
{
	if(pArray)
	{
		delete[] pArray;
		pArray = NULL;
	}
	capacity = 0;
	length = 0;
}

template <typename T>
int SeqLink<T>::getLength()
{
	return length;
}

template <typename T>
int SeqLink<T>::getCapacity()
{
	return capacity;
}

template <typename T>
int SeqLink<T>::insert(T &node, int pos)
{
	if(node != NULL || pos < 0)
	{
		return -1;
	}

	if(pos > capacity)
	{
		return -1;
	}

	int i = 0
	for(i = length; i > pos; i--)
	{
		pArray[i] = pArray[i-1];
	}
	pArray[i] = node;
	length ++

	return 0;
}

template <typename T>
int SeqLink<T>::getNode(T &t, int pos)
{
	if(node != NULL || pos < 0)
	{
		return -1;
	}

	return pArray[pos];
}

template <typename T>
void SeqLink<T>::deleteNode(int pos)
{
	if(node != NULL || pos < 0)
	{
		return -1;
	}
	
	int i = 0
	for(i = pos; i < length; i++)
	{
		pArray[i-1] = pArray[i];
	}
	length --;
	return;
}
