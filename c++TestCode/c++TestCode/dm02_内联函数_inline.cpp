#include "iostream"

using namespace std;

//ºê
#define MYFUNC(a, b)  ((a) < (b) ? (a) : (b))

//ÄÚÁªº¯Êý
inline int myfunc(int a, int b)
{
	return a < b ? a : b;
}

int main02()
{
	int a = 1, b = 2, c = 0;
	//c = MYFUNC(a++, b);
	
	c = myfunc(a++, b);

	cout<<"a == "<<a<<endl;
	cout<<"b == "<<b<<endl;
	cout<<"c == "<<c<<endl;

	system("pause");
	return 0;
}