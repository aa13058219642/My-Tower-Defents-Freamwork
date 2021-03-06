#pragma once
#include "stdfax.h"
#include "TowerDefentShare.h"
#include "GridPos.h"


class TowerSelectLayer : public Layer
{
public:
	TowerSelectLayer();
	~TowerSelectLayer();

	static TowerSelectLayer* create();
	virtual bool init();
	virtual void update(float dt);

	void cancel();

private:
	enum ETowerSelectLayerState{
		UnShow,
		ShowFor_EmptyPos,
		ShowFor_TowerPos,
		ShowFor_SpellPos,
		ShowFor_BuildTower,
		ShowFor_BuildSpellPos,
		ShowFor_BuildSpellTower
	};
	ETowerSelectLayerState m_state;
	GridPos* m_gridPos;

	Layer* selectLayer;
	Sprite* bg_circle;		//背景圈
	Sprite* bt_center;		//中心按钮
	Layer*  a_layer[8];		//周围按钮层
	Sprite* a_bt[8];		//周围按钮
	Sprite* a_bg[8];		//周围按钮下方提示信息背景
	Label* a_number[8];		//周围按钮下方提示信息数字


	void initSprite();
	void initListener();
	void hideAllButton();

	void show();
	void receiveMsg(Ref* pData);
	void showFor_EmptyPos(const NotificationMsg& msg);
	void showFor_TowerPos(const NotificationMsg& msg);
	void showFor_SpellPos(const NotificationMsg& msg);
	void showFor_BuildTower();
	void showFor_BuildSpellPos();
	void showFor_BuildSpellTower(const NotificationMsg& msg);

	bool onClick(Point pos);
	void clickEvent_showLayerFor_TowerInfo();
	void clickEvent_showLayerFor_BuildTower();
	void clickEvent_showLayerFor_BuildSpellPos();
	void clickEvent_buildTower(Direction dir);
	void clickEvent_buildSpellPos(Direction dir);
	void clickEvent_buildSpellTower(Direction dir);
	void clickEvent_sellTower();
	void clickEvent_sellSpellPos();
	void clickEvent_sellSpellTower();
};
