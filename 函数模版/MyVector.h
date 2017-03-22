#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
public:
	friend ostream& operator << <T>(ostream &out, const MyVector &obj);
public:
	//构造函数
	MyVector(int size);  
	//拷贝构造
	MyVector(const MyVector &obj);
	//析构函数
	~MyVector(void);

	int getLen();
public:
	T& operator[](int index);

	MyVector& operator=(const MyVector &obj);
protected:
	T *m_space;
	int m_length;
};

