#ifndef __BASE_GAME_ENTITY__
#define __BASE_GAME_ENTITY__

class BaseGameEntity
{
private:
	int	m_ID;   //唯一的标识

	static int m_nextVaildId;  // 下次有效的id

	void SetID(int id);  //设置id

public:
	BaseGameEntity::BaseGameEntity(int id)
	{
		SetID(id);
	}
	virtual BaseGameEntity::~BaseGameEntity()
	{
	}
	virtual void update()=0;
	int ID()const{return m_ID;}
};

#endif