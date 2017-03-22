#include "dm06_towFile.h"

using namespace std;

template <typename T>
Complex<T>::Complex(T a = 10, T b = 20)
{
	this->a = a;
	this->b = b;
}
	
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> c1)
{
	Complex d(0, 0);
	d.a = this->a + c1.a;
	d.b = this->b + c1.b;
	return d;
}
	
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> c1)
{
	Complex d(0, 0);
	d.a = this->a - c1.a;
	d.b = this->b - c1.b;
	return d;
}

template <typename T>
void Complex<T>::prinC()
{
	cout<<"a == "<<this->a<<endl;
	cout<<"b == "<<this->b<<endl;
}

template <typename T>
ostream & operator<<(ostream &out, Complex<T> &c3)
{
	out<<"a == "<<c3.a<<"\nb == "<<c3.b<<endl;
	return out;
}