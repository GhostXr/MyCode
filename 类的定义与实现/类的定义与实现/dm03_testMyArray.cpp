#include "iostream"
#include "MyArray.h"

using namespace std;

void main()
{
	MyArray a1(10);

	int i = 1;
	for(i = 1; i < a1.length(); i++)
	{
		a1.setData(i, i+10);
		cout<<"a1["<<i<<"] == "<<a1.getData(i)<<endl;
	}

	MyArray a2 = a1;
	for(i = 1; i < a1.length(); i++)
	{
		cout<<"a2["<<i<<"] == "<<a2.getData(i)<<endl;
	}

	system("pause");
	return;
}
