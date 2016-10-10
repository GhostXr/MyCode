#ifndef __MINER__
#define __MINER__

#include "BaseGameEntity.h"


class Miner : BaseGameEntity
{
public:
	Miner (int id);

	void update();  //�������ִ�еĸ�����麯��

	void ChangeState(State* pNewState);

private:
	State* m_pCurrentState;  //״ָ̬��

	location_type m_Location; //��ǰλ��

	int m_iGoldCarried;  //��ǰЯ���Ľ����

	int m_iMoneyInBack;  //���д�Ľ��

	int m_iThirst;  //��ǰ�ڿ�ֵ�� ���Ľ��Խ�� Խ�ڿ�

	int m_iFatigue;  //��ǰƣ��ֵ�� ���Ľ��Խ�� Խƣ��

};


#endif