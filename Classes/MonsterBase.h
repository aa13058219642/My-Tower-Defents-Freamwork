#pragma once
#include "stdfax.h"
#include "GameObject.h"
#include "GameMap.h"
class MonsterBase : public GameObject
{
public:
	MonsterBase();
	~MonsterBase();

	static MonsterBase* create(int MonsterID, MapPath path, bool isDebug = false);
	bool init(int MonsterID, MapPath path, bool isDebug = false);
	virtual void drawMyOutLine(DrawNode* drawNode);
	virtual void update(float dt);

	CC_SYNTHESIZE(MapPath, m_path, MovePath);

	virtual GameObjectType getObjectType();


private:
	Scale9Sprite* m_hpBar;

	void createAnimate(int MonsterID);

	virtual void onMove(float dt);
	virtual void onBeAttack(int damage);
	virtual void onDead(); 
	virtual void onBindSprite();
	void OnEndPoint();
};

