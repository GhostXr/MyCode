#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Complex
{
public:
	Complex(T a = 10, T b = 20);
	
	Complex operator+(Complex c1);
	
	Complex operator-(Complex c1);

	void prinC();

	friend ostream & operator<< <T>(ostream &out, Complex &c3);
private:
	T a, b;
};


