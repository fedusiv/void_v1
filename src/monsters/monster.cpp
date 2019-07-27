#include "monster.h"

Monster::Monster(MonsterAttribute attribute)
{
 _Attribute = attribute;
 _SkillQueue = new SkillsQueue();
}

FighterLiveStatus  Monster::defencePhaseFromWeaponHit(SkillAttackResult *attack)
{
   float damage_ =  _SkillQueue->DefenceFromWeaponHit(attack);
   return reduceHealth(damage_);
}

SkillAttackResult *Monster::attackPhase()
{
    // TODO : it is temporary
    SkillAttackResult * attack = _SkillQueue->makeWeaponHit(_Attribute.DamageStruct, _Attribute.Hand);
    return attack;
}


FighterLiveStatus Monster::reduceHealth(float value)
{
    _Attribute.Health -= value;
    if ( _Attribute.Health  <= 0)
    {
        return FighterLiveStatus::Death;
    }
    return FighterLiveStatus::Life;
}
