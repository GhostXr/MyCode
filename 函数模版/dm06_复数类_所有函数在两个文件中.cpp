#include <iostream>

#include "dm06_towFile.hpp"

using namespace std;

void main()
{
	Complex<int> c1(2, 1);
	Complex<int> c2(5, 6);

	Complex<int> c3 = c1+c2;
	//c3.prinC();
	cout<<c3<<endl;
	
	Complex<int> c4 = c1-c2;
	cout<<c4<<endl;

	system("pause");
	return;
}