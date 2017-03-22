#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(T t)
	{
		this->_t = t;
	}
	T getT()
	{
		return this->_t;
	}

private:
	T _t;
};
//派生普通类
class S : public A<int>
{
public:
	S(int a = 10, int b = 20) : A<int>(a)
	{
		this->b = b;
	}
	int printS()
	{
		cout<<"b = "<<this->b<<endl;
		cout<<"a = "<<this->getT()<<endl;
		return 0;
	}
private:
	int b;
};
//派生模版类
template <typename T>
class Q : public A<int>
{
public:
	Q(T q = 10, int a = 20) : A<int>(a)
	{
		this->q = q;
	}
	void printQ()
	{
		if (q.printS() == 0)
		{
			cout<<"q = "<<q.printS()<<endl;
			cout<<"a = "<<q.printS()<<endl;
		}
	}
private:
	T q;
};

void main()
{
	S b(5, 6);
	b.printS();

	Q<S> q(b, 50);
	q.printQ();

	system("pause");
	return;
}