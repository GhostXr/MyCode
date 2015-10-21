#include "iostream"

using namespace std;

void myFunc(int a)
{
	cout<<"a == "<<a<<endl;
}

void myFunc(char *p)
{
	cout<<"p == "<<p<<endl;
}

void myFunc(int a, int b)
{
	cout<<"a == "<<a<<"\nb == "<<b<<endl;
}

//����һ����������
typedef void myFuncType1(int a);

//����һ����������ָ��
typedef void (*myFuncType2)(char *a);

//����һ����������ָ�� ����
void (*myFuncTypeVar)(int a);

void main()
{
	//��������
	myFunc(1);
	myFunc("aaaa");
	myFunc(2, 3);

	//����ָ��
	//1
	myFuncType1 *mp1 = NULL;
	mp1 = myFunc;
	mp1(100);

	//2
	myFuncType2 mp2 = NULL;
	mp2 = myFunc;
	mp2("bbbbb");

	//3
	myFuncTypeVar = NULL;
	myFuncTypeVar = myFunc;
	myFuncTypeVar(200);

	system("pause");
	return;
}