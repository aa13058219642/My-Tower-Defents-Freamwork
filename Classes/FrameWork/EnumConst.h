#pragma once

/////////////////////////////////////////////////////////////////////////////
//Unit/////////////////////////////////////////////////////////////////

typedef unsigned int UnitType;
enum EUnitType : unsigned int
{
	Unit_Unit		= 1,
	Unit_Tower		= 1 << 1,
	Unit_Monster	= 1 << 2,
	Unit_Bullet		= 1 << 3,
	Unit_Land		= 1 << 4,
	Unit_Fly		= 1 << 5,
	Unit_Death		= 1 << 29,
	Unit_Destory	= 1 << 30
};

enum EUnitState{
	UnitState_Normal,
	UnitState_UsingSkill,
	UnitState_Death,
	UnitState_Destory
};



enum BulletType{ 
	Ball, 
	Missile 
};

/////////////////////////////////////////////////////////////////////////////
//CEffect/////////////////////////////////////////////////////////////////
#define DamageTypeCount 3
enum EDamageType : unsigned int{
	EDamageType_Weapon,
	EDamageType_Magic,
	EDamageType_Real

};

/////////////////////////////////////////////////////////////////////////////
//CSkill/////////////////////////////////////////////////////////////////


enum ESkillType
{
	ECSkill,
	ECSkillAttack,
	ECSkillEffect,
	ECSkillEffectInstant
};


enum ESkillEffectState
{
	SkillEffectState_ColdDowning,
	SkillEffectState_Ready,
	SkillEffectState_Approaching,
	SkillEffectState_Preparing,
	SkillEffectState_Beforing,
	SkillEffectState_Using,
	SkillEffectState_Aftering,
	SkillEffectState_End
};

/////////////////////////////////////////////////////////////////////////////
//CWeapon///////////////////////////////////////////////////////////////////////////
enum EWeapon_Upgradable
{
	WeaponUpgradable_Range,
	WeaponUpgradable_CoolDown,
	WeaponUpgradable_TargetCount,
	WeaponUpgradable_Filter,
	WeaponUpgradable_Damage,
	WeaponUpgradable_MinDamage,
	WeaponUpgradable_MaxDamage,
	WeaponUpgradable_DamageType
};


/////////////////////////////////////////////////////////////////////////////










