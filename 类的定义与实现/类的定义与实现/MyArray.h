#ifndef __MYARRAY__
#define __MYARRAY__

class MyArray
{
private:
	int myLength;
	int *mySpace;
public:
	MyArray(int length);
	MyArray(const MyArray &myA);
	int length();
	void setData(int index, int data);
	int getData(int index);
	~MyArray(void);
};

#endif // !1



