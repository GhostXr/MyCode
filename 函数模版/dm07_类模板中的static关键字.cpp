#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	static T m_a;
private:

};

template <typename T>
T A<T>::m_a = 0;

void main()
{
	A<int> a1, a2;
	a1.m_a = 2;
	a2.m_a ++;
	cout<<a1.m_a<<endl;

	A<char> b1;
	b1.m_a = 'a';
	b1.m_a ++;
	cout<<b1.m_a<<endl;

	system("pause");
	return;
}