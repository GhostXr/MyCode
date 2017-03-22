#include <iostream>
#include "deque"
using namespace std;

void printD(deque<int> d)
{
	for(deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout<<*it<<" ";
	}
}

void test1()
{
	deque<int> d1;

	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);

	d1.push_front(-1);
	d1.push_front(-3);
	d1.push_front(-5);

	cout<<"头部："<<d1.front()<<endl;
	
	cout<<"尾部："<<d1.back()<<endl;

	printD(d1);

	d1.pop_front();
	d1.pop_back();

	cout<<endl;
	printD(d1);
	cout<<endl;

	//查找数组下标
	deque<int>::iterator it = find(d1.begin(), d1.end(), 3);
	if (it != d1.end())
	{
		cout<< distance(d1.begin(), it)<<endl;
	}

}

void main()
{
	test1();

	system("pause");
	return;
}