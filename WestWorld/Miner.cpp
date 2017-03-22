#include "Miner.h"
#include <stdlib.h>

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

void Miner::ChangeState(State *pNewState)
{
	if (m_pCurrentState != NULL && pNewState != NULL)
	{
		m_pCurrentState->Exit(this);

		m_pCurrentState = pNewState;

		m_pCurrentState->Enter(this);
	};
}