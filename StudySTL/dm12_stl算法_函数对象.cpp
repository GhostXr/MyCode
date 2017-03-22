#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "vector"
#include "string"
#include "set"
#include "algorithm"
#include "functional"
using namespace std;

template <typename T>
class showElemt
{
public:
	showElemt()
	{
		n = 0;
	}
	void operator()(T &t)
	{
		n++;
		cout<<t<<endl;
	}
	void printN()
	{
		cout<<"n = "<<n<<endl;
	}
private:
	int n;
};


template <typename T>
void funcShowElemt1(T &t)
{
	cout<<t<<endl;
}

void funcShowElemt2(int t)
{
	cout<<t<<endl;
}

void test1()
{
	int a = 10;
	showElemt<int> se;
	se(a);
	cout<<endl;

	funcShowElemt1<int>(a);
	
	funcShowElemt1(a);
}

void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), showElemt<int>());//��������
	for_each(v1.begin(), v1.end(), funcShowElemt1<int>);//�ص�����
	for_each(v1.begin(), v1.end(), funcShowElemt2);//�ص�����

	showElemt<int> show1;
	//������������������
	//����������ֵ���ݣ��������ô���
	show1 = for_each(v1.begin(), v1.end(), show1);//��������
	show1.printN();
}

template <typename T>
class isDiv
{
public:
	isDiv(const T &t)
	{
		this->div = t;
	}
	bool operator()(T &t)
	{
		return (t%div == 0);
	}
private:
	T div;
};


void test03()
{
	vector<int> v1;
	v1.push_back(3);
	//v1.push_back(4);
	v1.push_back(6);
	v1.push_back(8);
	
	isDiv<int> div(4);
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), div);
	if (it == v1.end())
	{
		cout<<"û��"<<endl;
	}
	else
	{
		cout<<*it<<endl;
	}
}

//��Ԫ��������
template <typename T>
class sumAdd
{
public:
	T operator()(T &t1, T &t2)
	{
		return t1+t2;
	}

private:

};

void test04()
{
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(4);

	vector<int>::iterator it = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), sumAdd<int>());
	
	for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout<<*it<<endl;
	}
}

bool myCompare(const int &a, const int &b)
{
	return a<b;
}

void test05()
{
	vector<int> v;

	for(int i = 1; i < 10; i ++)
	{
		int temp = rand();
		v.push_back(temp);
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;
	//for_each(v.begin(), v.end(), showElemt<int>());

	sort(v.begin(), v.end(), myCompare);
	for_each(v.begin(), v.end(), showElemt<int>());
}

struct compareNoCase
{
	bool operator()(const string& str1, const string &str2)
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);
		
		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);

		return str1_ < str2_;
	}
};

void test06()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");
	set1.insert("ddd");

	set<string>::iterator it = set1.find("aaA"); //find Ĭ�����ִ�Сд
	if(it == set1.end())
	{
		cout<<"û���ҵ�"<<endl;
	}
	else
	{
		cout<<"�ҵ���"<<endl;
	}

	set<string, compareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");
	
	set<string, compareNoCase>::iterator it2 = set2.find("aaA"); //find Ĭ�����ִ�Сд
	if(it2 == set2.end())
	{
		cout<<"û���ҵ�"<<endl;
	}
	else
	{
		cout<<"�ҵ���"<<endl;
	}
}

void main()
{
	//test1();
	//test2(); //һԪ��������

	//test03(); //һԪν��
	
	//test04(); //��Ԫ��������

	//test05(); //��Ԫν��

	test06(); //��Ԫν����set�����е�Ӧ��

	system("pause");
	return;
}