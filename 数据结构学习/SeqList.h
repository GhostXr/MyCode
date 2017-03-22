#pragma once

typedef void SeqList;
typedef void SeqListNode;

SeqList* seqListCreate(int num);

void seqListDestory(SeqList* list);

void seqListClear(SeqList* list);

int seqListLength(SeqList* list);

int seqListCapaticy(SeqList* list);

int seqListInsert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* seqListGet(SeqList* list, int pos);

SeqListNode* seqListDelete(SeqList* list, int pos);
