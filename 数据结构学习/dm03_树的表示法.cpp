#include <iostream>
#include "LinkStack.h"

#include "stack"

using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

//先序遍历
void preOrder(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	printf("%d", t->data);
	preOrder(t->lChild);
	preOrder(t->rChild);
}

//中序遍历
void inOrder(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	inOrder(t->lChild);
	printf("%d", t->data);
	inOrder(t->rChild);
}

//后序遍历
void postOrder(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	postOrder(t->lChild);
	postOrder(t->rChild);
	printf("%d", t->data);
}

void countLeafNum(BiTNode *t, int* num)
{
	if(t != NULL)
	{
		if(t->lChild == NULL && t->rChild == NULL)
		{
			(*num) ++;
		}
		if(t->lChild)
		{
			countLeafNum(t->lChild, num);
		}
		if(t->rChild)
		{
			countLeafNum(t->rChild, num);
		}
	}
}

void countTreeHight(BiTNode *t, int* lNum, int* rNum)
{
	if(t == NULL)
	{
		return;
	}

	if(t->lChild)
	{
		(*lNum) ++;
		countTreeHight(t->lChild, lNum, rNum);
	}
	if(t->rChild)
	{
		(*rNum) ++;
		countTreeHight(t->rChild, lNum, rNum);
	}
}

BiTNode* checkLChild(BiTNode *t, stack<BiTNode*> &stack)
{
	if(t == NULL)
	{
		return t;
	}
	
	while (t->lChild)
	{
		stack.push(t);
		t = t->lChild;
	}

	return t;
}

void unRecursive(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	stack<BiTNode*> stack;

	t = checkLChild(t, stack);

	printf("\n %d ", t->data);
	while(t)
	{
		if(stack.size() > 0)
		{
			t = stack.top();
			stack.pop();
		}
		else
		{
			t = NULL;
		}
		if(t)
		{
			printf("%d ", t->data);

			if (t->rChild)
			{
				t = checkLChild(t->rChild, stack);
				printf("%d ", t->data);
			}
		}	
	}
}

void test01()
{
	BiTNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lChild = &t2;
	t1.rChild = &t3;
	t2.lChild = &t4;
	t2.rChild = NULL;
	t3.lChild = &t5;
	t3.rChild = NULL;
	t4.lChild = NULL;
	t4.rChild = NULL;
	t5.lChild = NULL;
	t5.rChild = NULL;

	//树的遍历
	preOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	postOrder(&t1);

	//求叶子节点的数量
	int num = 0;
	countLeafNum(&t1, &num);
	printf("\n num == %d", num);

	//求树的深度
	int rHight = 0;
	int lHight = 0;
	countTreeHight(&t1, &lHight, &rHight);
	
	int hight = (lHight > rHight ? lHight : rHight);
	printf("\n hight == %d", hight);


	//非递归遍历（中序）
	unRecursive(&t1);
}

void copyTree(BiTNode *t, BiTNode* tree)
{
	if(t == NULL)
	{
		return;
	}
	tree = (BiTNode*)malloc(sizeof(BiTNode*));

	if(t->lChild)
	{
		tree->data = t->data;
		copyTree(t->lChild, tree->lChild);
	}
	
	if(t->rChild)
	{
		tree->data = t->data;
		copyTree(t->rChild, tree->rChild);
	}
}
void test02()
{
	BiTNode *t1, *t2, *t3, *t4, *t5;
	t1 = (BiTNode*)malloc(sizeof(BiTNode*));
	t2 = (BiTNode*)malloc(sizeof(BiTNode*));
	t3 = (BiTNode*)malloc(sizeof(BiTNode*));
	t4 = (BiTNode*)malloc(sizeof(BiTNode*));
	t5 = (BiTNode*)malloc(sizeof(BiTNode*));

	t1->data = 1;
	t2->data = 1;
	t3->data = 1;
	t4->data = 1;
	t5->data = 1;
	
	t1->lChild = t2;
	t1->rChild = t3;
	t2->lChild = t4;
	t2->rChild = NULL;
	t3->lChild = t5;
	t3->rChild = NULL;
	t4->lChild = NULL;
	t4->rChild = NULL;
	t5->lChild = NULL;
	t5->rChild = NULL;
	
	//copy树
	BiTNode newT;
	copyTree(t1, &newT);
	
	preOrder(&newT);
}

typedef struct PBiTNode
{
	int parentPosition;
	int childTag;
	int data;
}PBiTNode;

typedef struct PBiTree
{
	PBiTNode node[100];
	PBiTNode rootNode;
	int nodeNum;
}PBiTree;

void test04()
{
	PBiTree pT;
	pT.nodeNum = 5;
	pT.node[0].data = 1; 

	pT.node[1].data = 2; 
	pT.node[1].parentPosition = 0; 
	pT.node[1].childTag = 1; 

	pT.node[2].data = 3; 
	pT.node[2].parentPosition = 0; 
	pT.node[2].childTag = 2; 

	pT.node[3].data = 4; 
	pT.node[3].parentPosition = 1; 
	pT.node[3].childTag = 1; 

	pT.node[4].data = 5; 
	pT.node[4].parentPosition = 2; 
	pT.node[4].childTag = 1; 
	pT.rootNode = pT.node[0];
}

void main()
{
	test01();  //二叉链表示法

	//test02(); //二叉链表示法
	
	//test03(); //三叉链表示法
	
	//test04(); //双亲链表示法

	system("pause");
	return;
}