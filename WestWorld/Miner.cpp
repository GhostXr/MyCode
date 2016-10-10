#include "Miner.h"

Miner::~Miner()
{
	
}

void Miner::update()
{
	m_iThirst += 1;
	if(m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}