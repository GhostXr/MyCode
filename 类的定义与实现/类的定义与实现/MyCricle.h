#pragma once
class MyCricle
{
public:
	void setCirCle(int x, int y, double r);
	int getPointX();
	int getPointY();
	double getCirCleR();
	int intersect(MyCricle &c);
private:
	int pX;
	int pY;
	double pR;
};

