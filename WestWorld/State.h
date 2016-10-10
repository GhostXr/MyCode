#ifndef __STATE__
#define __STATE__

#include "Miner.h"

class State
{
public:
	State();
	virtual ~State(){}
	
	virtual void Enter(Miner *)= 0;

private:

};

#endif