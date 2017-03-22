#ifndef __STATE__
#define __STATE__

#include "Miner.h"

class State
{
public:
	State();
	virtual ~State(){}
	
	virtual void Enter(Miner *)= 0;

	virtual void Execute(Miner *)= 0;

	virtual void Exit(Miner *)= 0;

};

#endif