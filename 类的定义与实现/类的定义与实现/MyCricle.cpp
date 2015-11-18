#include "MyCricle.h"
#include "math.h"

void MyCricle::setCirCle(int x, int y, double r)
{
	pX = x;
	pY = y;
	pR = r;
}

int MyCricle::getPointX()
{
	return pX;
}

int MyCricle::getPointY()
{
	return pY;
}

double MyCricle::getCirCleR()
{
	return pR;
}

//0, 两圆不相交
//1, 两圆相交
int MyCricle::intersect(MyCricle &c)
{
	int intersect = 0;
	double distance = sqrt((double)(c.getPointX() - pX)*(c.getPointX() - pX) + (c.getPointY() - pY)*(c.getPointY() - pY));
	if (distance <= (pR + c.getCirCleR()))
	{
		intersect = 1;
	}
	return intersect;
}