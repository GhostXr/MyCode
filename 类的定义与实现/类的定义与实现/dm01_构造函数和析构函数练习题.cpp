#include "iostream"

using namespace std;

class ABCD
{
public:
	ABCD(int _a) 
	{
		a = _a;
		cout<<"create ABCD , a == "<<a<<endl;
	}
	~ABCD()
	{
		cout<<"disapper ABCD , a == "<<a<<endl;
	}
	int getA()
	{
		return a;
	}
private:
	int a;
};

class TestABCD
{
public:
	TestABCD() : a1(1), a2(2), m(100)
	{
		cout<<"create TestABCD with NULL "<<endl;
	}
	~TestABCD()
	{
		cout<<"disapper TestABCD "<<endl;
	}
	TestABCD(const TestABCD &ta) : a1(3), a2(4), m(200)
	{
		cout<<"create TestABCD with Copy "<<endl;
	}
private:
	ABCD a1;
	ABCD a2;
	const int m;
};

TestABCD doThing(TestABCD t)
{
	TestABCD t2 = t;
	return t2;
}

void Test1()
{
	TestABCD t1;
	doThing(t1);

	return;
}

//匿名对象的生命周期
void Test2()
{
	cout<<"start Test2"<<endl;
	ABCD(1); // 执行完构造函数后立刻执行析构函数

	ABCD b = ABCD(2);
	
	cout<<"end Test2"<<endl;
}

void main03()
{
	//Test1();
	Test2();
	system("pause");
	return;
}