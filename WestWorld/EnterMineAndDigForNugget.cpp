#include "EnterMineAndDigForNugget.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	if (pMiner->Location() != goldMine)
	{
		cout<< "\n" << GetNameOfEntity(pMiner->ID()) << ": Pickin' up a nugget!" <<endl;
	}
}