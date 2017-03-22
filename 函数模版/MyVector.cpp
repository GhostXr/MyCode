#include "MyVector.h"
 
template <typename T>
ostream& operator <<(ostream &out, const MyVector<T> &obj)
{
	for(int i = 0; i < obj.m_length; i++)
	{
		out <<obj.m_space[i]<<endl;
	}
	return out;
}

template <typename T>
MyVector<T>::MyVector(int size)
{
	m_space = new T[size];
	m_length = size;
} 

template <typename T>
MyVector<T>::MyVector(const MyVector &obj)
{
	m_length = obj.m_length;
	m_space = new T[m_length];

	for(int i = 0; i < m_length; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}
	//Îö¹¹º¯Êý
template <typename T>
MyVector<T>::~MyVector(void)
{
	if(m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_length = 0;
	}
}

template <typename T>
int MyVector<T>::getLen()
{
	return m_length;
}

template <typename T>
T& MyVector<T>::operator[](int index)
{
	return m_space[index];
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj)
{
	if(m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_length = 0;
	}
	
	m_length = obj.m_length;
	m_space = new T[m_length];

	for(int i = 0; i < m_length; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;
}
