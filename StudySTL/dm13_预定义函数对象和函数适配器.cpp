#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "vector"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;

void test1()
{
	plus<int> intAdd;
	int a = 10;
	int b = 20;
	int c = intAdd(a, b);

	cout<< c <<endl;
	
	plus<string> intString;
	string x = "aa";
	string y = "bb";
	string z = intString(x, y);

	cout<< z <<endl;

	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("bb");
	v1.push_back("cccc");;
	v1.push_back("cc");;
	v1.push_back("cc");
	v1.push_back("z");
	
	sort(v1.begin(), v1.end(), greater<string>());

	for(vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<*it<<endl;
	}

	//求ccc出现的个数
	//bind2nd是函数适配器，绑定预定义函数对象和参数
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), "cc"));
	//int num = count_if(v1.begin(), v1.end(), equal_to<string>());
	cout<<"num == "<<num<<endl;
}

class isGreat
{
public:
	isGreat(int i)
	{
		this->num = i;
	}
	bool operator()(int &n)
	{
		return n > this->num;
	}
private:
	int num;
};

void test2()
{
	vector<int> v1;
	for(int i = 0; i < 10; i++)
	{
		v1.push_back(i+1);
	}

	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<*it<<endl;
	}

	int num = count(v1.begin(), v1.end(), 3);
	cout<<"num == "<<num<<endl;

	//通过谓词，求大于2的个数
	int num1 = count_if(v1.begin(), v1.end(), isGreat(2));
	cout<<"num1 == "<<num1<<endl;

	//通过预定义的函数对象，求大于2的个数
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 4));
	cout<<"num3 == "<<num3<<endl;

	//求奇数的个数
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout<<"num4 == "<<num4<<endl;
	
	//求偶数的个数
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout<<"num5 == "<<num5<<endl;
}

void main()
{
	//test1();
	
	test2(); //函数适配器综合案例
	system("pause");
	return;
}