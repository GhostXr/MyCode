#include "stdlib.h"
#include <string.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}SLIST_NODE;

//创建链表
SLIST_NODE *CREATE_SLIST()
{
	SLIST_NODE *pHead, *pCurrent, *pMalloc;
	int date;

	pHead = (SLIST_NODE *)malloc(sizeof(SLIST_NODE));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->pNext = NULL;

	pCurrent = pHead;

	printf("please enter current date:");
	scanf("%d", &date);

	while (date != -1)
	{
		pMalloc = (SLIST_NODE *)malloc(sizeof(SLIST_NODE));
		if (pMalloc == NULL)
		{
			return NULL;
		}
		pMalloc->data = date;
		pMalloc->pNext = NULL;

		pCurrent->pNext = pMalloc;

		pCurrent = pMalloc;

		printf("please enter current date:", date);
		scanf("%d", &date);
	}

	return pHead;
}

//遍历打印链表
int TRAVERSAL_SLIST(SLIST_NODE *pHead)
{
	SLIST_NODE *pCurrent;

	if (pHead == NULL)
	{
		return -1;
	}

	pCurrent = pHead;
	
	while (pCurrent->pNext != NULL)
	{
		pCurrent = pCurrent->pNext;
		printf("%d \n", pCurrent->data);
	}

	return 0;
}

//插入x元素
int INSTER_SLIST(SLIST_NODE *pHead)
{
	SLIST_NODE *pCurrent, *pInster;
	int count = 0, date, position;

	if (pHead == NULL)
	{
		return -1;
	}
	pCurrent = pHead;

	printf("please enter inster date:");
	scanf("%d", &date);

	printf("please enter inster position:");
	scanf("%d", &position);

	if (date == NULL || position == NULL)
	{
		return -1;
	}
	pInster = (SLIST_NODE *)malloc(sizeof(SLIST_NODE));
	if (pInster == NULL)
	{
		return -2;
	}
	pInster->data = date;

	while (pCurrent->pNext != NULL)
	{
		if (count == position)
		{
			pInster->pNext = pCurrent->pNext;
			pCurrent->pNext = pInster;
			goto END;
		}
		else
		{
			pCurrent = pCurrent->pNext;
			count ++;
		}
	}
	pCurrent->pNext = pInster;
	pInster->pNext = NULL;

END:
	return 0;
}

//删除x元素
int DELETE_SLIST(SLIST_NODE *pHead)
{   
	SLIST_NODE *pCurrent, *pDelete, *pPre;
	int count = 0, position;

	if (pHead == NULL)
	{
		return -1;
	}
	pCurrent = pHead;

	printf("please enter delete position:");
	scanf("%d", &position);

	while (pCurrent->pNext != NULL)
	{
		if (count == position)
		{
			pDelete = pCurrent->pNext;
			pCurrent->pNext = pDelete->pNext;

			if (pDelete != NULL)
			{
				free(pDelete);
				pDelete = NULL;
			}
			return 0;
		}
		else
		{
			pCurrent = pCurrent->pNext;
			count ++;
		}
	}

	return 0;
}

//链表逆置
int SLIST_REVERSE(SLIST_NODE *pHead)
{
	SLIST_NODE *pCur, *pPre, *temp;
	if (pHead == NULL)
	{
		return -1;

	}
	pPre = pHead->pNext;

	if (pPre->pNext == NULL)
	{
		return 0;
	}
	pCur = pPre->pNext;
	pPre->pNext = NULL;

	while (pCur->pNext != NULL)
	{
		temp = pCur->pNext;
		pCur->pNext = pPre;
		pPre = pCur;
		pCur = temp;
	}
	pCur->pNext = pPre;
	pHead->pNext = pCur;
	return 0;
}

//链表销毁
int SLIST_DESTORY(SLIST_NODE *pHead)
{
	SLIST_NODE *pCurrent;

	if (pHead == NULL)
	{
		return -1;
	}
	while (pHead->pNext != NULL)
	{
		pCurrent = pHead->pNext;
		free(pHead);
		pHead = pCurrent;
	}
	return 0;
}

int main()
{
	SLIST_NODE *pHead;
	int ret = 0;

	pHead = CREATE_SLIST();
	if (pHead == NULL)
	{
		printf("CREATE_SLIST is Error");
		return 0;
	}
	
	ret = INSTER_SLIST(pHead);
	if (ret != 0)
	{
		printf("INSTER_SLIST is Error");
		return 0;
	}

	ret = TRAVERSAL_SLIST(pHead);
	if (ret != 0)
	{
		printf("TRAVERSAL_SLIST is Error");
		return 0;
	}
	
	ret = DELETE_SLIST(pHead);
	if (ret != 0)
	{
		printf("DELETE_SLIST is Error");
		return 0;
	}

	ret = TRAVERSAL_SLIST(pHead);
	if (ret != 0)
	{
		printf("TRAVERSAL_SLIST is Error");
		return 0;
	}

	ret = SLIST_REVERSE(pHead);
	if (ret != 0)
	{
		printf("SLIST_REVERSE is Error");
		return 0;
	}

	ret = TRAVERSAL_SLIST(pHead);
	if (ret != 0)
	{
		printf("TRAVERSAL_SLIST is Error");
		return 0;
	}

	ret = SLIST_DESTORY(pHead);
	if (ret != 0)
	{
		printf("SLIST_DESTORY is Error");
		return 0;
	}

	system("pause");
	return 0;
}