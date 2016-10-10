#ifndef __MINER__
#define __MINER__

#include "BaseGameEntity.h"


class Miner : BaseGameEntity
{
public:
	Miner (int id);

	void update();  //子类必须执行的父类的虚函数

	void ChangeState(State* pNewState);

private:
	State* m_pCurrentState;  //状态指针

	location_type m_Location; //当前位置

	int m_iGoldCarried;  //当前携带的金块数

	int m_iMoneyInBack;  //银行存的金块

	int m_iThirst;  //当前口渴值， 带的金块越多 越口渴

	int m_iFatigue;  //当前疲劳值， 带的金块越多 越疲劳

};


#endif