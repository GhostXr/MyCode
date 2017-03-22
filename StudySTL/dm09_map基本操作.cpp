#include <iostream>
#include "map"
#include "string"
using namespace std;

void test1()
{
	map<int, int> st;
	cout<<"大小："<<st.size()<<endl;
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

//插入方法的比较
void test02()
{
	map<int, int> st;
	cout<<"大小："<<st.size()<<endl;
	for(int i = 0; i < 10; i++)
	{
		int temp = rand();
		//插入相同的key覆盖
		//st[i] = temp;

		//返回pair
		//插入相同的key报错
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

//查找异常处理
void test03()
{
	map<int, string> st;
	cout<<"大小："<<st.size()<<endl;

	st.insert(pair<int, string>(1, "你好1"));
	st.insert(pair<int, string>(2, "你好2"));
	st.insert(pair<int, string>(3, "你好3"));
	st.insert(pair<int, string>(4, "你好4"));
	st.insert(pair<int, string>(5, "你好5"));

	map<int, string>::iterator it = st.find(8);
	if(it == st.end())
	{
		cout<<"没有要查找的值"<<endl;
	}
	else
	{
		cout<<"找到了查找的"<<it->first<<"它的值是"<<it->second<<endl;
	}

	cout<<endl;
	pair<map<int, string>::iterator, map<int, string>::iterator> pair1 = st.equal_range(6);
	if(pair1.first == st.end())
	{
		cout<<"没有要查找的大于等于的值"<<endl;
	}
	else
	{
		cout<<"大于等于的 = "<<pair1.first->first<<" "<<pair1.first->second<<endl;
	}
	if(pair1.second == st.end())
	{
		cout<<"没有要查找的大于的值"<<endl;
	}
	else
	{
		cout<<"大于的 = "<<pair1.second->first<<" "<<pair1.second->second<<endl;
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