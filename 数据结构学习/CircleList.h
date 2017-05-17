#pragma once

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;

CircleList* circleListCreate();

void circleListDestory(CircleList* list);

void circleListClear(CircleList* list);

int circleListLength(CircleList* list);

int circleListInsert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* circleListGet(CircleList* list, int pos);

CircleListNode* circleListDelete(CircleList* list, int pos);

CircleListNode* circleListDeletNode(CircleList* list, CircleListNode* node);

CircleListNode* circleListReset(CircleList* list);

CircleListNode* circleListCurrent(CircleList* list);
	
CircleListNode* circleListNext(CircleList* list);
