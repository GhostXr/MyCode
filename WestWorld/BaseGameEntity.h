#ifndef __BASE_GAME_ENTITY__
#define __BASE_GAME_ENTITY__

class BaseGameEntity
{
private:
	int	m_ID;   //Ψһ�ı�ʶ

	static int m_nextVaildId;  // �´���Ч��id

	void SetID(int id);  //����id

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