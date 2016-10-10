#include "iostream"
#include "MyArray.h"

using namespace std;

void main()
{
	MyArray a1(10), a2(10), a3(10);
	int i = 1;
	for(i = 0; i < a1.length(); i++)
	{
		//a1.setData(i, i+10);
		//a2.setData(i, i+11);
		//cout<<"a1["<<i<<"] == "<<a1.getData(i)<<endl;

		//жиди[]
		a1[i] = (i+10);
		a2[i] = (i+10);
		cout<<"a1["<<i<<"] == "<<a1[i]<<endl;
	}

	//a2 = a1;
	//a3 = a2 = a1;
	for(i = 0; i < a1.length(); i++)
	{
		//cout<<"a2["<<i<<"] == "<<a2.getData(i)<<endl;
		//жиди[]
		cout<<"a2["<<i<<"] == "<<a2[i]<<endl;
		//cout<<"a3["<<i<<"] == "<<a3[i]<<endl;
	}

	//жиди!=
	if(a1 != a2)
	{
		printf("a1 != a2\n");
	}
	else
	{
		printf("a1 == a2\n");
	}

	system("pause");
	return;
}
