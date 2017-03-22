#include <iostream>

using namespace std;

#include "MyVector.cpp"

void main()
{
	MyVector<int> my1(10);
	for(int i = 0; i < my1.getLen(); i++)
	{
		my1[i] = i+1;
		cout<<my1[i]<<endl;
	}
	
	MyVector<int> my2(my1);
	for(int i = 0; i < my2.getLen(); i++)
	{
		cout<<my2<<endl;
	}
	system("pause");
	return;
}