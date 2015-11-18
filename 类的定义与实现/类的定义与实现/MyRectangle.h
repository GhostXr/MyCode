#ifndef __MYRECTANGLE_H__
#define __MYRECTANGLE_H__

#include "MyPoint.h"

class MyRectangle
{
public:
	void setRectangle(MyPoint &p1, MyPoint &p2);
	MyPoint getPleftDown();
	MyPoint getPRightUp();
	int calculateRectV();
private:
	MyPoint pLeftDown; 
	MyPoint pRightUp; 
};

#endif // DEBUG

