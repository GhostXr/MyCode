// 03�����ļ���д��Ŀ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "cfg_op.h"

#define CFGNAME "c:/cfg.ini"

void mysenu()
{
	printf("======================\n");
	printf("1 ����д�����ļ�\n");
	printf("2 ���Զ������ļ�\n");
	printf("0 �˳�\n");
	printf("======================\n");
}

//��������
int TgetCfg()
{
	char value[1024] = {0};
	char key[1024] = {0};
	int *len = 0;
	int rect = 0;

	printf("\n ������key:");
	scanf("%s", key);

	//rect = GetCfgItem(CFGNAME, key, value, len);
	if (rect != 0)
	{
		printf("func GetCfgItem is error: %d", rect);
		return rect;
	}

	printf("\n %s == %s \n", key, value);
	return 0;
}

//д������
int TWriteCfg()
{
	int Len = 1024, rect = 0;
	char Name[1024] = {0};
	char value[1024] = {0};
	char key[1024] = {0};

	printf("\n ������key:");
	scanf("%s", key);

	
	printf("\n ������value:");
	scanf("%s", value);

	rect = WriteCfgItem(CFGNAME, key, value, Len);
	if (rect != 0)
	{
		printf("func GetCfgItem is error: %d", rect);
		return rect;
	}
	
	printf("\n��������� %s == %s \n", key, value);

	return 0;
}

int main()
{
	int choice;

	for(;;)
	{
		mysenu();

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			TgetCfg();
			break;
		case 2:
			TWriteCfg();
			break;
		case 0:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}

	printf("hello.....\n");
	system("pause");
	return 0;
}

