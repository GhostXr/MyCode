#ifndef __CFG_OP_H__
#define __CFG_OP_H__


#ifdef  __cplusplus
extern "C" {
#endif
//��ȡ������
int GetCfgItem(char *FileName, char *pKey, char *pValue, int *pValueLen);


//д������
int WriteCfgItem(char *FileName, char *pItemName, char *pItemValue, int ItemValueLen);

#ifdef  __cplusplus
}
#endif

#endif
