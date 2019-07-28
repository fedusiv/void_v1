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
    SkillAttackResult * attack = _SkillQueue->makeWeaponHit(_Attribute.damageStruct, _Attribute.Hand);
    return attack;
}


FighterLiveStatus Monster::reduceHealth(float value)
{
    _Attribute.health -= value;
    if ( _Attribute.health  <= 0)
    {
        return FighterLiveStatus::Death;
    }
    return FighterLiveStatus::Life;
}
