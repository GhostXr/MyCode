#include "MyTree.h"


void MyTree::treeGrow(int years = 0)
{
	if (ages < 0)
	{
		ages = 0;
	}
	ages += years;
}

void MyTree::setAges(int age = 0)
{
	ages = age;
}

int MyTree::getTreeAge()
{
	return ages;
}