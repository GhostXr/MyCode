#pragma once
#include "LinkStackNode.h"
#include <stdio.h>

class LinkStack
{
public:
	LinkStack();

	void linkStackCreate();

	void linkStackDestory();

	void linkStackClear();

	int linkStackLength();

	int linkStackPush( LinkStackNode* node);

	LinkStackNode* linkStackPop();

	LinkStackNode* linkStackGetTop();
private:
	LinkStackNode* topNode;
	LinkStack* stack;
};
