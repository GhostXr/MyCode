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
		//printf("����һ��Ҷ�ӽڵ�");
		return NULL;
	}
	else
	{
		temp = (BiTNode *)malloc(sizeof(BiTNode));
		if(temp == NULL)
		{
			return NULL;
		}

		temp->data = h;   //����һ�����ڵ�
		//printf("����һ�������� %c", h);
		temp->lChild = createTree();     //����������
		
		//printf("����һ�������� %c", h);
		temp->rChild = createTree();     //����������

		return temp;
	}
}

//�������
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
		//printf("����һ��Ҷ�ӽڵ�");
		return NULL;
	}
	else
	{
		temp = (BiTNode *)malloc(sizeof(BiTNode));
		if(temp == NULL)
		{
			return NULL;
		}

		temp->data = h;   //����һ�����ڵ�
		//printf("����һ�������� %c", h);
		temp->lChild = createTree();     //����������
		
		//printf("����һ�������� %c", h);
		temp->rChild = createTree();     //����������

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
	test01();    // #����һ����
	
	test02();    // ��������򴴽�һ����

	system("pause");
	return;
}