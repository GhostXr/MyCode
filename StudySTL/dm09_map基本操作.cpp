#include <iostream>
#include "map"
#include "string"
using namespace std;

void test1()
{
	map<int, int> st;
	cout<<"��С��"<<st.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		//st[i] = temp;
		st.insert(pair<int, int>(i, temp));
		//st.insert(make_pair(i, temp));
		//st.insert(map<int, int>::value_type(i, temp));
	}

	for(map<int, int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<it->first <<" "<<it->second<<endl;
	}
	cout<<endl;

	while (!st.empty())
	{
		map<int, int>::iterator it = st.begin();
		cout<<it->first <<" "<<it->second<<endl;
		st.erase(it);
	}
}

//���뷽���ıȽ�
void test02()
{
	map<int, int> st;
	cout<<"��С��"<<st.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		//������ͬ��key����
		//st[i] = temp;

		//����pair
		//������ͬ��key����
		pair<map<int, int>::iterator, bool> pair1 = st.insert(pair<int, int>(i, temp));
		printf("1= %d, 2= %d", pair1.second, pair1.first->second);
		cout<<endl;
		//st.insert(make_pair(i, temp));
		//st.insert(map<int, int>::value_type(i, temp));
	}
	pair<map<int, int>::iterator, bool> pair1 = st.insert(pair<int, int>(1, 100));
		printf("1= %d, 2= %d", pair1.second, pair1.first->second);
		cout<<endl;

	for(map<int, int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<it->first <<" "<<it->second<<endl;
	}
	cout<<endl;
}

//�����쳣����
void test03()
{
	map<int, string> st;
	cout<<"��С��"<<st.size()<<endl;

	st.insert(pair<int, string>(1, "���1"));
	st.insert(pair<int, string>(2, "���2"));
	st.insert(pair<int, string>(3, "���3"));
	st.insert(pair<int, string>(4, "���4"));
	st.insert(pair<int, string>(5, "���5"));

	map<int, string>::iterator it = st.find(8);
	if(it == st.end())
	{
		cout<<"û��Ҫ���ҵ�ֵ"<<endl;
	}
	else
	{
		cout<<"�ҵ��˲��ҵ�"<<it->first<<"����ֵ��"<<it->second<<endl;
	}

	cout<<endl;
	pair<map<int, string>::iterator, map<int, string>::iterator> pair1 = st.equal_range(6);
	if(pair1.first == st.end())
	{
		cout<<"û��Ҫ���ҵĴ��ڵ��ڵ�ֵ"<<endl;
	}
	else
	{
		cout<<"���ڵ��ڵ� = "<<pair1.first->first<<" "<<pair1.first->second<<endl;
	}
	if(pair1.second == st.end())
	{
		cout<<"û��Ҫ���ҵĴ��ڵ�ֵ"<<endl;
	}
	else
	{
		cout<<"���ڵ� = "<<pair1.second->first<<" "<<pair1.second->second<<endl;
	}

	cout<<endl;
	for(map<int, string>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout<<it->first <<" "<<it->second<<endl;
	}
}

void main()
{
	//test1();

	//test02();

	test03();

	system("pause");
	return;
}