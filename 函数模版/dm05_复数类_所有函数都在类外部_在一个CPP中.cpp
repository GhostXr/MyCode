#include <iostream>

using namespace std;

template <typename T>
class Complex
{
public:
	Complex(T a = 10, T b = 20);
	
	Complex operator+(Complex c1);
	
	Complex operator-(Complex c1);

	void prinC();

	friend ostream & operator<< <T>(ostream &out, Complex &c3);
private:
	T a, b;
};

template <typename T>
Complex<T>::Complex(T a = 10, T b = 20)
{
	this->a = a;
	this->b = b;
}

template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> c1)
{
	Complex d(0, 0);
	d.a = this->a + c1.a;
	d.b = this->b + c1.b;
	return d;
}

template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> c1)
{
	Complex d(0, 0);
	d.a = this->a - c1.a;
	d.b = this->b - c1.b;
	return d;
}

template <typename T>
void Complex<T>::prinC()
{
	cout<<"a == "<<this->a<<endl;
	cout<<"b == "<<this->b<<endl;
}

/*
滥用友元函数报错
原因:模版是两次编译生成的，第一次编译生成的函数头和第二次生成的不一样
dm05_复数类_所有函数都在类外部_在一个CPP中.obj : error LNK2019: 无法解析的外部符号 
"class std::basic_ostream<char,struct std::char_traits<char> > & 
__cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)" 
(??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)，该符号在函数 _main 中被引用	
*/
template <typename T>
ostream&operator<<(ostream &out, Complex<T> &c3)
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
	
	Complex<int> c4 = c1-c2;
	cout<<c4<<endl;

	system("pause");
	return;
}