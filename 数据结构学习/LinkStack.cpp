#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

using namespace std;

LinkStack::LinkStack()
{
	stack = (LinkStack*)linkListCreate();
	topNode = NULL;
}

void LinkStack::linkStackDestory()
{
	if(stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}

void LinkStack::linkStackClear()
{
	if (stack != NULL)
	{
		linkListClear((LinkList*)stack);
	}
}

int LinkStack::linkStackLength()
{
	int temp = linkListLength((LinkList*)stack);
	return temp;
}

int LinkStack::linkStackPush(LinkStackNode* node)
{
	if (stack == NULL || node == NULL)
	{
		return -1;
	}
	
	int temp = linkListInsert((LinkList*)stack, (LinkListNode*)node, 0);
	if(temp != 0)
	{
		printf(" insert stack is error");
	}
	topNode = node;
	return 0;
}

LinkStackNode* LinkStack::linkStackPop()
{
	
	if (stack == NULL)
	{
		return NULL;
	}

	LinkStackNode* temp;
	LinkStackNode* current = (LinkStackNode*)linkListDelete((LinkList*)stack, 0);
	temp = current;
	topNode = (LinkStackNode*)linkListGet((LinkList*)stack, 0);
	if (current == NULL)
	{
		printf(" pop stack is error");
	}
	current = NULL;

	return temp;
}

LinkStackNode* LinkStack::linkStackGetTop()
{
	return topNode;
}

