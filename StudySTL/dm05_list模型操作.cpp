#include <iostream>
#include "list"
using namespace std;

void test1()
{
	list<int> ls;
	cout<<"大小："<<ls.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		ls.push_back(i);
	}

	cout<<"头部："<<ls.front()<<endl;
	cout<<"尾部："<<ls.back()<<endl;
	cout<<"大小："<<ls.size()<<endl;

	list<int>::iterator it = ls.begin();
	while(it != ls.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;

	//list不支持随机访问
	it = ls.begin();
	it++;
	it++;
	it++;
	//it = it + 5;

	ls.insert(it, 100);
	while(! ls.empty())
	{
		int temp = ls.front();
		cout<< temp <<" ";
		ls.pop_front();
	}
	//链表的index从0开始
	//在3号位置插入元素，原来的3号变成4号

	cout<<endl;

	for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		cout<<*it<<" ";
	}

}

//list删除左闭右开  [0, 3), 删除0， 1， 2
void test2()
{
	list<int> ls;
	for(int i = 0; i < 10; i++)
	{
		ls.push_back(i);
	}

	list<int>::iterator it1 = ls.begin();
	list<int>::iterator it2 = ls.begin();
	it2++;
	it2++;
	it2++;

	ls.erase(it1, it2);
	
	ls.remove(7);
	
	for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		cout<<*it<<" ";
	}
}

void main()
{
	//test1();
	test2();

	system("pause");
	return;
}