#ifndef __MYARRAY__
#define __MYARRAY__

class MyArray
{
private:
	int myLength;
	int *mySpace;
public:
	MyArray(int length);
	//MyArray(const MyArray &myA);
	int length();
	void setData(int index, int data);
	int getData(int index);
	~MyArray(void);

//运算符重载
public:

	//重载[]
	int& operator[](int i);

	//重载=

	//重载!=
	bool operator!=(MyArray &a);
};

#endif // !1



