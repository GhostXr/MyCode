#include <iostream>

using namespace std;

template <typename T>
class Complex
{
public:
	Complex(T a = 10, T b = 20)
	{
		this->a = a;
		this->b = b;
	}
	
	Complex operator+(Complex c1)
	{
		Complex d(0, 0);
		d.a = this->a + c1.a;
		d.b = this->b + c1.b;
		return d;
	}

	void prinC()
	{
		cout<<"a == "<<this->a<<endl;
		cout<<"b == "<<this->b<<endl;
	}

	friend ostream&operator<<(ostream &out, Complex &c3);
private:
	T a, b;
};

ostream&operator<<(ostream &out, Complex<int> &c3)
{
	out<<"a == "<<c3.a<<"\nb == "<<c3.b<<endl;
	return out;
}

void main()
{
	Complex<int> c1(2, 1);
	Complex<int> c2(5, 6);

	Complex<int> c3 = c1+c2;

	//c3.prinC();
	cout<<c3<<endl;

	system("pause");
	return;
}