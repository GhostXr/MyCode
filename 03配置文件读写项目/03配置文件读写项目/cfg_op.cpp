#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//∂¡≈‰÷√œÓ
int GetCfgItem(char *FileName, char *pKey, char *pValue, int *pValueLen)
{
	int rect = 0;
	char buf[1024] = {0};

	FILE *fp = NULL;

	fp = fopen(FileName, "r");
	if (fp == NULL)
	{
		return -1;
	}

	while (feof(fp))
	{
		//fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		fgets(buf, 1024, fp);
		buf[strlen(buf) + 1] = '\0';
		char *p = strstr(buf, pKey);
		if(p != NULL)
		{
			return -1;
		}
	}

	fclose(fp);
	return 0;
}

//–¥≈‰÷√œÓ
int WriteCfgItem(char *FileName, char *pItemName, char *pItemValue, int ItemValueLen)
{
	int rect = 0;
	FILE *fp = NULL;
	char buf[1024] = {0};

	if (FileName == NULL)
	{
		return -1;
	}

	fp = fopen(FileName, "w+");
	if (fp = NULL)
	{
		return -2;
	}

	strcat(buf, pItemName);
	strcat(buf, "=");
	strcat(buf, pItemValue);
	//fputs(_In_z_ const char * _Str, _Inout_ FILE * _File);

	fputs(buf, fp);

	fclose(fp);

	return rect;
}