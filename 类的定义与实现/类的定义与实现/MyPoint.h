#pragma once
class MyPoint
{
public:
	void setPoint(int x1, int y1);
	int getPointX();
	int getPointY();
	double calculateDistance(MyPoint &y);
private:
	int x1;
	int y1;
};

