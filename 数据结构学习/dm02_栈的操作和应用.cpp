#include <iostream>

#include "LinkStack.h"
#include "LinkList.h"
#include "CircleList.h"

using namespace std;

typedef struct Teacher
{
	LinkStackNode *node;
	int age;
	char name[4];
}Tech;

void test01()
{
	
	LinkStack stack = LinkStack();
	
	Tech t1, t2, t3, t4;
	t1.age = 34;
	t2.age = 44;
	t3.age = 64;
	t4.age = 35;
	stack.linkStackPush((LinkStackNode*)&(t1));
	stack.linkStackPush((LinkStackNode*)&(t2));
	stack.linkStackPush((LinkStackNode*)&(t3));
	stack.linkStackPush((LinkStackNode*)&(t4));

	int length = stack.linkStackLength();
	for(int i = 0; i <length; i++)
	{
		Tech* temp = (Tech*)stack.linkStackPop();
		cout<<temp->age<<" ";
	}
	cout<<endl;
}

bool isLeft(char str)
{
	switch (str)
	{
	case '<':
		return true;
	case '(':
		return true;
	case '{':
		return true;
	case '[':
		return true;
	default:
		return false;
	}
}

bool isRight(char str)
{
	switch (str)
	{
	case '>':
		return true;
	case ')':
		return true;
	case '}':
		return true;
	case ']':
		return true;
	default:
		return false;
	}
}
bool isMatch(char strLeft, char strRight)
{
	if (strLeft == '<' && strRight == '>')
	{
		return true;
	}
	else if (strLeft == '(' && strRight == ')')
	{
		return true;
	}
	else if (strLeft == '{' && strRight == '}')
	{
		return true;
	}
	else if (strLeft == '[' && strRight == ']')
	{
		return true;
	}
	else
	{
		return false;
	}
}

typedef struct Value
{
	LinkStackNode* node;
	char str;
}Value;


void test02()
{
	char code[100] = "#include st(dio).h> void main(){ system('pause'); return 0; }";

	LinkStack stack = LinkStack();
	Value value[100];

	int i = 0;
	while(code[i] != '\0')
	{       
		if(isLeft(code[i]))
		{
			value[i].str = code[i];
			stack.linkStackPush((LinkStackNode*)&(value[i]));
		}

		if(isRight(code[i]))
		{
			Value* temp = (Value*)stack.linkStackPop();
			if (temp == NULL || isMatch(temp->str, code[i]) == false)
			{
				printf("invaild error");
				return;
			}
		}
		i++;

	}
	
	if(stack.linkStackGetTop() == NULL)
	{
		printf("success");
	}
	else
	{
		printf("invaild error");
	}
}

bool isOperator(char str)
{
	switch (str)
	{
	case '*':
		return true;
	case '-':
		return true;
	case '/':
		return true;
	case '+':
		return true;
	default:
		return false;
	}
}

bool checkLevel(char str)
{
	if (str == '+' || str == '-' || str == '(')
	{
		return false;
	}
	else
	{
		return true;
	}
}

int express(char oper, int numLeft, int numRight)
{ 
	switch (oper)
	{
	case '*':
		return numLeft * numRight;
	case '-':
		return numLeft - numRight;
	case '/':
		return numLeft / numRight;
	case '+':
		return numLeft + numRight;
	default:
		return 0;
	}

}

void test04(char* code)
{
	char* newCode[100];
	
	LinkStack stack = LinkStack();
	Value value[100];
	int i = 0, j = 0, num = 0;
	while(code[i] != '\0')
	{
		int tmp = (int)code[i];
		if (tmp >= 48 && tmp <= 57)
		{
			value[i].str = code[i];
			stack.linkStackPush((LinkStackNode*)&(value[i]));
		}
		if(isOperator(code[i]))
		{
			int value1, value2;
			Value* temp1 = (Value*)stack.linkStackPop();
			value1 = atoi(&temp1->str);

			if (num == 0)
			{
				Value* temp2 = (Value*)stack.linkStackPop();
				value2 = atoi(&temp2->str);
			}
			else
			{
				value2 = num;
			}

			num = express(code[i], value2, value1);
		}
		i++;
	}
	
	printf(" num == %d ", num);
}

void test03()
{
	char code[100] = "1+2*(6/(2*3)+7)";
	char newCode[100];
	
	LinkStack stack = LinkStack();
	Value value[100];

	//中缀转后缀
	int i = 0, j = 0, k = 0;
	while(code[i] != '\0')
	{
		int tmp = (int)code[i];
		if (tmp >= 48 && tmp <= 57)
		{
			newCode[j] = code[i];
			j++;
		}
		if(isLeft(code[i]))
		{
			value[k].str = code[i];
			stack.linkStackPush((LinkStackNode*)&(value[k]));
			k++;
		}
		if(isOperator(code[i]))
		{
			Value* temp = (Value*)stack.linkStackGetTop();
			if(temp != NULL && checkLevel(temp->str))
			{
				Value* temp = (Value*)stack.linkStackPop();
				newCode[j] = temp->str;
				j++;
			}
			value[k].str = code[i];
			stack.linkStackPush((LinkStackNode*)&(value[k]));
			k++;
		}
		if(isRight(code[i]))
		{
			for(int k = 0; k < stack.linkStackLength(); k++)
			{
				Value* temp = (Value*)stack.linkStackPop();
				if(isLeft(temp->str))
				{
					break;
				}
				newCode[j] = temp->str;
				j++;
			}
		}
		i++;
	}
	
	for(int k = 0; k < stack.linkStackLength(); k++)
	{
		Value* temp = (Value*)stack.linkStackPop();
		newCode[j] = temp->str;
		j++;
	}

	for(i = 0; i < j; i++)
	{
		printf("%c ", newCode[i]);
	} 

	printf("\n");
	//后缀计算
	//test04(newCode);
}

void main()
{
	//test01();  //栈的基本操作
	
	//test02();  //栈的应用1， 就近匹配
	
	test03();  //栈的应用2， 中缀转后缀计算

	system("pause");
	return;
}