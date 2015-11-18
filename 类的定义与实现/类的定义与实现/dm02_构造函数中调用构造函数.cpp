#include "iostream"

using namespace std;

class MyTest
{
public:
	MyTest(int _a, int _b)
	{
		this->a = _a;
		this->b = _b;
		MyTest(this->a, this->b, 100);
	}
	MyTest(int _a, int _b, int _c)
	{
		this->a = _a;
		this->b = _b;
		this->c = _c;
	}
	~MyTest()
	{
		
	}
public:
	int getC()
	{
		return c;
	}
	void setC(int _c)
	{
		this->c = _c;
	}
private:
	int a;
	int b;
	int c;
};

void main04()
{
	MyTest t1(1, 2);

	cout<<"c === "<<t1.getC()<<endl;
	system("pause");
	return;
}