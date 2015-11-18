#include "MyRectangle.h"


void MyRectangle::setRectangle(MyPoint &p1, MyPoint &p2)
{
	pLeftDown = p1;
	pRightUp = p2; 
}

MyPoint MyRectangle::getPleftDown()
{
	return pLeftDown;
}

MyPoint MyRectangle::getPRightUp()
{
	return pRightUp;
}

int MyRectangle::calculateRectV()
{
	int width = (pRightUp.getPointX() - pLeftDown.getPointX());
	int height = (pRightUp.getPointY() - pLeftDown.getPointY());
	int rectV = width * height;
	return rectV;
}
