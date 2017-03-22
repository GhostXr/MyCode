#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(T *t)
	{
		this->_t = t;
	}
	T* getT()
	{
		return this->_t;
	}

private:
	T* _t;
};

template <typename T>
void useA(T t)
{
	cout<<t.getT()<<endl;
}

void main()
{
	A<char> a("hao");
	int c = 20;
	A<int>  b(&c);
	useA<A<char>>(a);
	//cout<<a.getT()<<endl;
	system("pause");
	return;
}