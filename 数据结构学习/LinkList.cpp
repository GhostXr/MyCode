#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _tag_LinkList
{
	LinkListNode headNode;
	int length;

}TLinkList;

LinkList* linkListCreate()
{
	TLinkList *temp = NULL;

	temp = (TLinkList*)malloc(sizeof(TLinkList));
	memset(temp, 0, sizeof(TLinkList));
	temp->length = 0;
	temp->headNode.next = NULL;

	return temp;
}

void linkListDestory(LinkList* list)
{
	if(list != NULL)
	{
		free(list);
		list = NULL;
	}

	return;
}

void linkListClear(LinkList* list)
{
	TLinkList* tList = NULL;
	if(list == NULL)
	{
		return;
	}
	tList = (TLinkList*)list;

	tList->length = 0;
	tList->headNode.next = NULL;

	return;
}

int linkListLength(LinkList* list)
{
	TLinkList* tList = NULL;
	if(list == NULL)
	{
		return 0;
	}
	tList = (TLinkList*)list;

	return tList->length;
}

int linkListInsert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tList = NULL;
	if(list == NULL || node == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TLinkList*)list;

	LinkListNode *tNode = NULL;
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
	tList->length ++;

	return 0;
}

LinkListNode* linkListGet(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	if(list == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TLinkList*)list;
	
	LinkListNode *tNode = NULL;
	tNode = &(tList->headNode);
	for(int i = 0; i < pos; i++)
	{
		tNode = tNode->next;

	}
	return tNode->next;
}

LinkListNode* linkListDelete(LinkList* list, int pos)
{
	TLinkList* tList = NULL;
	if(list == NULL || pos < 0)
	{
		return 0;
	}
	tList = (TLinkList*)list;


	LinkListNode *tNode = NULL;
	LinkListNode *tNextNode = NULL;
	tNode = &(tList->headNode);

	for(int i = 0; i < pos; i++)
	{
		tNode = tNode->next;

	}
	tNextNode = tNode->next;
	if (tNextNode == NULL)
	{
		tNode->next = NULL;
	}
	else
	{
		tNode->next = tNextNode->next;
	}
	tList->length --;

	return tNextNode;
}