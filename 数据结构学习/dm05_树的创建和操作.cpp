#include <iostream>

using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

BiTNode* createTree()
{
	BiTNode* temp = NULL;
	char h;
	scanf("%c", &h);

	if(h == '#')
	{
		//printf("创建一个叶子节点");
		return NULL;
	}
	else
	{
		temp = (BiTNode *)malloc(sizeof(BiTNode));
		if(temp == NULL)
		{
			return NULL;
		}

		temp->data = h;   //生成一个根节点
		//printf("创建一个左子树 %c", h);
		temp->lChild = createTree();     //构造左子树
		
		//printf("创建一个右子树 %c", h);
		temp->rChild = createTree();     //构造右子树

		return temp;
	}
}

//先序遍历
void preOrder(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	printf("%c", t->data);
	preOrder(t->lChild);
	preOrder(t->rChild);
}

void freeTree(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}

	if(t->lChild)
	{
		freeTree(t->lChild);
		t->lChild = NULL;
	}
	
	if(t->rChild)
	{
		freeTree(t->rChild);
		t->rChild = NULL;
	}

	if(t)
	{
		free(t);
		t = NULL;
	}
}

void test01()
{
	BiTNode* t;
	t = createTree();

	preOrder(t);

	freeTree(t);
}


BiTNode* createTree2()
{
	BiTNode* temp = NULL;
	char h;
	scanf("%c", &h);

	if(h == '#')
	{
		//printf("创建一个叶子节点");
		return NULL;
	}
	else
	{
		temp = (BiTNode *)malloc(sizeof(BiTNode));
		if(temp == NULL)
		{
			return NULL;
		}

		temp->data = h;   //生成一个根节点
		//printf("创建一个左子树 %c", h);
		temp->lChild = createTree();     //构造左子树
		
		//printf("创建一个右子树 %c", h);
		temp->rChild = createTree();     //构造右子树

		return temp;
	}
}

void test02()
{
	BiTNode* t;
	t = createTree2();

	preOrder(t);

	freeTree(t);
}

void main()
{
	test01();    // #创建一棵树
	
	test02();    // 中序和先序创建一棵树

	system("pause");
	return;
}