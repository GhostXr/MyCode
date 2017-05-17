#include <iostream>

using namespace std;

void test01()
{
	int a[10] = {34, 53, 1, 56, 6, 2, 7, 4, 2, 10};

	for(int i = 0; i < 10; i++)
	{
		for(int j = i+1; j < 10; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for(int i = 0; i < 10; i++)
	{
		cout<<"a[i] = "<<a[i]<<endl;
	}
}

void test02()
{
	int a[10] = {34, 53, 1, 56, 6, 2, 7, 4, 2, 10};
	int i = 0, j = 0;
	int key = -1;

	for(i = 1; i < 10; i++)
	{
		int temp = a[i];
		key = i;
		for(j = i-1; (j >= 0); j--)
		{
			if(temp < a[j])
			{
				a[j+1] = a[j];
				key = j;
			}
		}
		a[key] = temp;
	}

	for(i = 0; i < 10; i++)
	{
		cout<<"a[i] = "<<a[i]<<endl;
	}
}

void test03()
{
	int a[10] = {34, 53, 1, 56, 6, 2, 7, 4, 2, 10};
	int i = 0, j = 0;
	int key = 1;   //0已排好序， 1是还未排好序

	//向上
	/*{
		for(i = 1; i < 10 && key == 1; i++)
		{
			key = 0;
			for(j = 0; j < 10-i; j++)
			{
				if(a[j] > a[j+1])
				{
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					key = 1;
				}
			}
		}
	}*/

	//向下
	{
		for(i = 0; i < 10 && key == 1; i++)
		{
			key = 0;
			for(j = 10-1; j > i; j--)
			{
				if(a[j-1] > a[j])
				{
					int temp = a[j-1];
					a[j-1] = a[j];
					a[j] = temp;
					key = 1;
				}
			}
		}
	}

	for(i = 0; i < 10; i++)
	{
		cout<<"a[i] = "<<a[i]<<endl;
	}
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int getMidNum(int a[], int low, int heigh)
{
	int num = a[low];
	while( low < heigh)
	{
		while((low < heigh) && (a[heigh] >= num))
		{
			heigh --;
		}
		swap(a, low, heigh);
		while((low < heigh) && (a[low] <= num))
		{
			low ++;
		}
		swap(a, low, heigh);
	}

	return low;
}

void sort(int a[], int low, int heigh)
{
	if (low < heigh)
	{
		int midNum = -1;
		midNum = getMidNum(a, low, heigh);

		sort(a, low, midNum - 1);
		sort(a, midNum + 1, heigh);
	}
	return;
}

void test04()
{
	int a[10] = {34, 53, 1, 56, 6, 2, 7, 4, 2, 10};
	int low = 0, heigh = 9;
	
	sort(a, low, heigh);

//	cout<<"midNum == "<<midNum<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout<<"a[i] = "<<a[i]<<endl;
	}
}

void test05()
{
	int a, b, c, d;
	a = 10;
	b = a++;
	c = ++a;
	d = 10*a++;

	cout<<a<<" "<<b<<" "<<c<<" "<<d;
}

void test06()
{
	int a = 91;
	char b = a + '0';

	printf("b = %s\n", b);
	if (b == '91')
	{
		printf("b = 5\n");
	}
}

class A
{
public:
	A()
	{
		a = 1;
	}
	void m(int &x)
	{
		printf("A");
	}
	int a;
};

class B : public A
{
public:
	void m(float &x, int &y)
	{
		printf("B");
	}
};

void main()
{
	//test01();  //选择法排序

	//test02();  //插入排序

	//test03();   //冒泡排序

	//test04();   //快速排序

	//test05();

	B b;
	A a = b;
	int x = 1;
	float y = 1.0;
	a.m(x);
	b.m(y,x);

	//test06();

	system("pause");

	return;
}