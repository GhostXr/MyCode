#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "vector"
#include "string"
#include "set"
#include "algorithm"
#include "functional"
#include "numeric"

using namespace std;

void printV(vector<int> &vt)
{
	for(vector<int>::iterator it = vt.begin(); it != vt.end(); it++)
	{
		cout<<*it<<endl;
	}
}

template <typename T>
int showElemt(T &t)
{
	cout<<t<<endl;
	return t;
}

class myShow
{
public:
	myShow()
	{
		num = 0;
	}
	void operator()(int &t)
	{
		num++;

		cout<<t<<endl;
		t = t+1;
	}

	void printN()
	{
		cout<<num<<endl;
	}
private:
	int num;
};

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), showElemt<int>);//函数对象

	myShow myshow;
	myshow = for_each(v1.begin(), v1.end(), myshow);//函数对象
	myshow.printN();
	for_each(v1.begin(), v1.end(), showElemt<int>);//函数对象
	
}

int increase(int &i)
{
	int a = i + 100;
	return a;
}

void test2()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);
	cout<<endl;
	v2.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), increase);
	printV(v2);
	cout<<endl;

	//预定义的函数对象
	transform(v1.begin(), v1.end(), v2.begin(), negate<int>());
	printV(v2);
	cout<<endl;
	
	//函数适配器
	transform(v1.begin(), v1.end(), v2.begin(), bind2nd(multiplies<int>(), 3));
	printV(v2);
	cout<<endl;
	
	
	//输出
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), bind2nd(multiplies<int>(), 3));
	cout<<endl;
}

//1. for_each 回调函数没有返回值，参数使用引用；
//   transform 必须要有返回值， 参数不是引用
void test03()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	
	for_each(v1.begin(), v1.end(), showElemt<int>);//函数对象
	
	transform(v2.begin(), v2.end(), v2.begin(),showElemt<int>);
}

void test04()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if(it == v1.end())
	{
		cout<<"没找到"<<endl;
	}
	else
	{
		cout<<*it<<endl;
	}
	int index = distance(v1.begin(), it);
	cout<<index<<endl;
}

//二分法查找
void test05()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);

	bool find = binary_search(v1.begin(), v1.end(), 3);
	if(find)
	{
		cout<<"找到了"<<endl;
	}
	else
	{
		cout<<"没找到"<<endl;
	}
}

void test06()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	int num = count(v1.begin(), v1.end(), 2);
	if(num)
	{
		cout<<"找到了"<<num<<endl;
	}
	else
	{
		cout<<"没找到"<<endl;
	}
}


void test07()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(6);
	v1.push_back(5);

	int num = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 3));
	if(num)
	{
		cout<<"找到了"<<num<<endl;
	}
	else
	{
		cout<<"没找到"<<endl;
	}
}

void test08()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);

	vector<int>::iterator num = find(v1.begin(), v1.end(), 3);
	if(num != v1.end())
	{
		cout<<"找到了"<<*num<<endl;
	}
	else
	{
		cout<<"没找到"<<endl;
	}
	
	vector<int>::iterator num1 = find_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	if(num1 != v1.end())
	{
		cout<<"找到了"<<*num1<<endl;
	}
	else
	{
		cout<<"没找到"<<endl;
	}
}

void test09()
{
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(v1.size() + v2.size());

	vector<int>::iterator it = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	printV(v3);
}

bool sortV(int &t1, int &t2)
{
	return t1 < t2;
}

void test10()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	
	printV(v1);

	sort(v1.begin(), v1.end(), sortV);
	
	printV(v1);
}

void test11()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	
	sort(v1.begin(), v1.end(), sortV);
	printV(v1);

	random_shuffle(v1.begin(), v1.end());

	printV(v1);

	string str = "diojanw";
	
	random_shuffle(str.begin(), str.end());
	cout<<str<<endl;

}

void test12()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	
	reverse(v1.begin(), v1.end());
	printV(v1);	
}

void test13()
{
	vector<int> v1, v2;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);

	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());

	printV(v2);
}

void test14()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);

	replace(v1.begin(), v1.end(), 3, 10);
	printV(v1);
	cout<<endl;
	replace_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 5), 20);
	printV(v1);
}

void test15()
{
	vector<int> v1, v2;
	v1.push_back(3);
	v1.push_back(6);
	v2.push_back(5);
	v2.push_back(3);
	v2.push_back(4);

	swap(v1, v2);
	printV(v1);
	cout<<endl;
	printV(v2);
}

void test16()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);

	int sum = accumulate(v1.begin(), v1.end(), 100);
	cout<< sum <<endl;
}

void test17()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);

	fill(v1.begin()+2, v1.end(), 20);
	printV(v1);

}

void test18()
{
	vector<int> v1, v2, v3;

	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(11);
	
	v2.push_back(8);
	v2.push_back(12);
	v2.push_back(22);
	v2.push_back(45);
	v2.push_back(62);

	v3.resize(v1.size()+v2.size());

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
	cout<<endl;
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
	cout<<endl;
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}

void main()
{
	//test1();  //for_each
	//test2();	//transform

	//test03(); //for_each 和 transform 比较
	
	//查找
	//test04(); //adjacent_find

	//test05(); //binary_search 

	//test06(); //count
	
	//test07(); //count_if

	//test08(); //find and find_if

	//排序
	//test09(); //merge
	
	//test10(); //sort

	//test11(); //random

	//test12(); //revrese  逆序

	//copy
	//test13();   //cpoy

	//test14();  //replace and replace_if

	//test15();   //swap 交换

	//test16();  //accumulate  累加求和

	//test17(); //fill 填充

	//集合
	test18();

	system("pause");
	return;
}