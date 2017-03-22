#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	friend ostream& operator << <T>(ostream &out, const MyVector &obj);
public:
	//���캯��
	MyVector(int size);  
	//��������
	MyVector(const MyVector &obj);
	//��������
	~MyVector(void);

	int getLen();
public:
	T& operator[](int index);

	MyVector& operator=(const MyVector &obj);
protected:
	T *m_space;
	int m_length;
};

