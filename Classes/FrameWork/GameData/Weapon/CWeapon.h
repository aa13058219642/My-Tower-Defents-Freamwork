#pragma once
#include "stdfax.h"
#include "EnumConst.h"
#include "Ability.h"

class CEffect;

class CWeapon
{
public:
	/*命中率*/
	Ability<float> chance;
	/*射程*/
	Ability<float> Range;
	/*CD*/
	Ability<float> CoolDown;
	/*最大同时攻击目标*/
	Ability<int> TargetCount;
	/*目标过滤*/
	UnitType Filter;
	/*伤害类型*/
	AbilityKey<EDamageType> DamageType;
	///*最小伤害*/
	//Ability<float> MinDamage;
	///*最大伤害*/
	//Ability<float> MaxDamage;
	/*伤害*/
	AbilityValueEx<float> Damage;


	/*爆炸范围*/
	Ability<float> BoomRange;
	/*攻击附带效果*/
	AbilityKey<string> attack_Effect;
	/*命中效果动画*/
	AbilityKey<string> attack_Animate;
	/*暴击率*/
	Ability<float> criticalChance;
	/*暴击伤害倍率*/
	Ability<float> criticalMultiplier;
	/*暴击附带效果(暴击时，攻击附带效果与暴击附带效果一起发动)*/
	AbilityKey<string> critical_Effect;
	/*暴击效果动画*/
	AbilityKey<string> critical_Animate;

	/*演员名称*/
	AbilityKey<string> ActorName;
	/*前摇时间*/
	float beforing_Delay;
	/*施放时间*/
	float using_Delay;
	/*后摇时间*/
	float aftering_Delay;
	/*前摇动画*/
	string beforing_Animate;
	/*施放动画*/
	string using_Animate;
	/*后摇动画*/
	string aftering_Animate;

	/*子弹类型*/
	BulletType bulletType;
	/*是否追踪目标*/
	bool IsTrackTarget;
	/*是否面向目标*/
	bool IsFaceToTarget;
	/*子弹移动速度*/
	float BulletSpeed;

	CWeapon();
	~CWeapon();
	CWeapon* clone();

	void clearAbility();

	//CWeapon* getCurWeapon();
	//template <typename T>
	//void Upgrade(EWeapon_Upgradable type, T value);
	//void Downgrade();


private:


};

