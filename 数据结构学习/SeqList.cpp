#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_SeeList
{
	int length;
	int capacity;
	unsigned int *node;
}TSeqList;

SeqList* seqListCreate(int num)
{
	TSeqList* temp = NULL;
	temp = (TSeqList*)malloc(sizeof(TSeqList));
	if (temp == NULL)
	{
		printf("seqListCreate is error");
	}
	memset(temp, 0, sizeof(TSeqList));

	temp->node = (unsigned int *)malloc(sizeof(unsigned int *)*num);
	if (temp->node == NULL)
	{
		printf("malloc temp->node is error");
		return NULL;
	}

	return temp;
}

void seqListDestory(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
		tlist->node = NULL;
	}
	free(tlist);
}

void seqListClear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TSeqList*)list;
	tlist->length = 0;
	return;
}

int seqListLength(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList*)list;
	return tlist->length;
}

int seqListCapaticy(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return - 1;
	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

int seqListInsert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList *tlist = NULL;
	if (list == NULL || node != NULL || pos > 0)
	{
		return -1;
	}
	tlist = (TSeqList*)list;
	if (tlist->length >= tlist->capacity)
	{
		return 1;
	}

	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	int i = 0;
	for(i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	tlist->node[i] = (unsigned int)node;
	tlist->length ++;

	return 0;
}

SeqListNode* seqListGet(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	if (list == NULL || pos > 0)
	{
		return NULL;
	}
	tlist = (TSeqList*)list;

	return (SeqListNode*)tlist->node[pos];
}

SeqListNode* seqListDelete(SeqList* list, int pos)
{
	TSeqList *tlist = NULL;
	if (list == NULL || pos > 0)
	{
		return NULL;
	}
	tlist = (TSeqList*)list;
	
	SeqListNode* ret = (SeqListNode*)tlist->node[pos];
	int i = 0;
	for(i = pos+1; i < tlist->length; i++)
	{
		tlist->node[i-1] = tlist->node[i];
	}
	tlist->length --;

	return ret;
}

