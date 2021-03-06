#include "CEffectDamage.h"
#include "Helper.h"
CEffectDamage::CEffectDamage(float minDamage, float maxDamage, EDamageType damageType, Name effectAnimate, int parentID, int targetID)
{
	this->m_MinDamage = minDamage;
	this->m_MaxDamage = maxDamage;
	this->m_damageType = damageType;
	this->m_effectAnimate = effectAnimate;
	this->m_parentID = parentID;
	this->m_targetID = targetID;
}


CEffectDamage::~CEffectDamage()
{

}

void CEffectDamage::execute()
{
	Unit* target = getTarget();
	if (target != nullptr)
	{
		target->onBeAttack(Helper::rand(m_MinDamage, m_MaxDamage), m_damageType);
		target->applyAEffect(m_effectAnimate);
	}

	this->setState(ECEffectState::ECEffectState_Death);


}

CEffect* CEffectDamage::clone()
{
	CEffectDamage* effect = new CEffectDamage(m_MinDamage, m_MaxDamage, m_damageType, m_effectAnimate);
	return effect;
}
