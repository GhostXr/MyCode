#include "MyPoint.h"
#include "math.h"

void MyPoint::setPoint(int x, int y)
{
	x1 = x;
	y1 = y;
}

int MyPoint::getPointX()
{
	return x1;
}

int MyPoint::getPointY()
{
	return y1;
}

double MyPoint::calculateDistance(MyPoint &y)
{
	double distance = sqrt((double)(y.getPointX() - x1)*(y.getPointX() - x1) + (y.getPointY() - y1)*(y.getPointY() - y1));
	return distance;
}
