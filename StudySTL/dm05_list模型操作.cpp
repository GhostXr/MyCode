#include <iostream>
#include "list"
using namespace std;

void test1()
{
	list<int> ls;
	cout<<"��С��"<<ls.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		ls.push_back(i);
	}

	cout<<"ͷ����"<<ls.front()<<endl;
	cout<<"β����"<<ls.back()<<endl;
	cout<<"��С��"<<ls.size()<<endl;

	list<int>::iterator it = ls.begin();
	while(it != ls.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;

	//list��֧���������
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
	//�����index��0��ʼ
	//��3��λ�ò���Ԫ�أ�ԭ����3�ű��4��

	cout<<endl;

	for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		cout<<*it<<" ";
	}

}

//listɾ������ҿ�  [0, 3), ɾ��0�� 1�� 2
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