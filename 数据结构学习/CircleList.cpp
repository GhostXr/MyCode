#include "CircleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_LinkList
{
	CircleListNode headNode;
	CircleListNode* slider;
	int length;

}TCircleList;

CircleList* circleListCreate()
{
	TCircleList *temp = NULL;

	temp = (TCircleList*)malloc(sizeof(TCircleList));
	memset(temp, 0, sizeof(TCircleList));
	temp->length = 0;
	temp->headNode.next = NULL;
	temp->slider = NULL;

	return temp;
}

void circleListDestory(CircleList* list)
{
	if(list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

void circleListClear(CircleList* list)
{
	TCircleList* tList = NULL;
	if(list == NULL)
	{
		return;
	}
	tList = (TCircleList*)list;
	tList->slider = NULL;
	tList->length = 0;
	tList->headNode.next = NULL;

	return;	
}

int circleListLength(CircleList* list)
{
	TCircleList* tList = NULL;
	if(list == NULL)
	{
		return 0;
	}
	tList = (TCircleList*)list;

	return tList->length;
}

int circleListInsert(CircleList* list, CircleListNode* node, int pos)
{	TCircleList* tList = NULL;
	if(list == NULL || node == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TCircleList*)list;

	CircleListNode *tNode = NULL;
	tNode = &(tList->headNode);

	if (pos > tList->length)
	{
		pos = tList->length;
	}

	for(int i = 0; i < pos; i++)
	{
		tNode = tNode->next;
	}
	node->next = tNode->next;
	tNode->next = node;

	if(tList->length == 0)
	{
		tList->slider = node;
	}
	tList->length ++;

	if(tNode == (CircleListNode*)tList)
	{
		CircleListNode* last = circleListGet(tList, tList->length-1);
		last->next = tNode->next;
	}

	return 0;
}

CircleListNode* circleListGet(CircleList* list, int pos)
{
	TCircleList* tList = NULL;
	if(list == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TCircleList*)list;
	
	CircleListNode *tNode = NULL;
	tNode = &(tList->headNode);
	for(int i = 0; i < pos; i++)
	{
		tNode = tNode->next;

	}
	return tNode->next;
}

CircleListNode* circleListDelete(CircleList* list, int pos)
{
	TCircleList* tList = NULL;
	if(list == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TCircleList*)list;


	CircleListNode *tNode = NULL;
	CircleListNode *tNextNode = NULL;
	CircleListNode *last = NULL;
	tNode = &(tList->headNode);

	for(int i = 0; i < pos; i++)
	{
		tNode = tNode->next;

	}
	tNextNode = tNode->next;
	tNode->next = tNextNode->next;
	tList->length --;

	if(last != NULL)
	{
		tList->headNode.next = tNode;
		last->next = tNextNode->next;
	}

	if(tList->slider == tNextNode)
	{
		tList->slider = tNextNode->next;
	}

	return tNextNode;
}

CircleListNode* circleListDeletNode(CircleList* list, CircleListNode* node)
{
	TCircleList* tList = NULL;
	if(list == NULL || node == NULL)
	{
		return 0;
	}
	tList = (TCircleList*)list;

	
	CircleListNode *tNode = NULL;
	CircleListNode *tNextNode = NULL;
	tNode = &(tList->headNode);

	for(int i = 0; i < tList->length; i ++)
	{
		if (tNode->next == node)
		{
			tNextNode = circleListDelete(tList, i);
		}
	}

	return tNextNode;
}

CircleListNode* circleListReset(CircleList* list)
{	TCircleList* tList = NULL;
	if(list == NULL)
	{
		return 0;
	}
	tList = (TCircleList*)list;
	
	tList->slider = tList->headNode.next;

	return tList->slider;
}

CircleListNode* circleListCurrent(CircleList* list)
{
	TCircleList* tList = NULL;
	if(list == NULL)
	{
		return 0;
	}
	tList = (TCircleList*)list;
	
	CircleListNode *tNode = tList->slider;

	return tNode;
}
	
CircleListNode* circleListNext(CircleList* list)
{	
	TCircleList* tList = NULL;
	if(list == NULL)
	{
		return 0;
	}
	tList = (TCircleList*)list;
	
	CircleListNode *tNode = tList->slider;
	tList->slider = tNode->next;

	return tNode;
}
