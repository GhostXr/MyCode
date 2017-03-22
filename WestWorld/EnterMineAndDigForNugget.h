#ifndef __ENTER_MINE_AND_DIG_FOR_NUGGET__
#define __ENTER_MINE_AND_DIG_FOR_NUGGET__

#include "State.h"

class EnterMineAndDigForNugget : public State
{
private:
	EnterMineAndDigForNugget(){};

public:
	static EnterMineAndDigForNugget* Instence();

	virtual void Enter(Miner *);
	
	virtual void Execute(Miner *);
	
	virtual void Exit(Miner *);
};

#endif