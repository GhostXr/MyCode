// 03配置文件读写项目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "cfg_op.h"

#define CFGNAME "c:/cfg.ini"

void mysenu()
{
	printf("======================\n");
	printf("1 测试写配置文件\n");
	printf("2 测试读配置文件\n");
	printf("0 退出\n");
	printf("======================\n");
}

//读配置项
int TgetCfg()
{
	char value[1024] = {0};
	char key[1024] = {0};
	int *len = 0;
	int rect = 0;

	printf("\n 请输入key:");
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

//写配置项
int TWriteCfg()
{
	int Len = 1024, rect = 0;
	char Name[1024] = {0};
	char value[1024] = {0};
	char key[1024] = {0};

	printf("\n 请输入key:");
	scanf("%s", key);

	
	printf("\n 请输入value:");
	scanf("%s", value);

	rect = WriteCfgItem(CFGNAME, key, value, Len);
	if (rect != 0)
	{
		printf("func GetCfgItem is error: %d", rect);
		return rect;
	}
	
	printf("\n您输入的是 %s == %s \n", key, value);

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

