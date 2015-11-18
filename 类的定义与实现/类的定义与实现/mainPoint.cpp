#include "iostream"
#include "MyPoint.h"
#include "MyCricle.h"
#include "MyRectangle.h"
#include "MyTree.h"

using namespace std;

void main02()
{
	MyPoint p1, p2;
	double distance = 0;

	p1.setPoint(5, 9);
	p2.setPoint(-1, -8);

	distance = p1.calculateDistance(p2);
	cout<<"p1 - p2 distance == "<<distance<<endl;

	MyRectangle rect;
	rect.setRectangle(p1, p2);
	int rectV = rect.calculateRectV();
	cout<<"rect v == "<<rectV<<endl;

	MyCricle c1, c2;
	c1.setCirCle(0, 0, 3);
	c2.setCirCle(0, 9, 5);
	int intersect = c1.intersect(c2);
	if (intersect == 0)
	{
		cout<<"两圆不相交"<<endl;
	}
	else if (intersect == 1)
	{
		cout<<"两圆相交"<<endl;
	}

	MyTree tree1;
	//tree1.setAges(5);
	tree1.treeGrow(2);
	cout<<"tree age is "<<tree1.getTreeAge()<<endl;
	
	system("pause");
	return;
}