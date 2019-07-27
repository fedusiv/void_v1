#include "skillattack.h"

SkillAttack::SkillAttack(SkillAttackAttribure attribute) : Skill (attribute.BaseAttribute )
{
    _AttributeAttack = attribute;
}

void SkillAttack::processAttack(SkillAttackResult *attack)
{

}

void SkillAttack::processCritical(SkillAttackResult *attack)
{
    attack->addNewCritical(values.criticalValue,values.criticalChanse);
}

void SkillAttack::ChangeTypeFromTo(SkillAttackResult *attack)
{
    attack->changeTypeFromTo(values.fromType, values.newType);
}





SkillAttackResult::SkillAttackResult(PlayerWeaponDamage damage, WeaponHands hand)
{
    _defaultDamage = damage;
    _defaultHand = hand;
    for ( int i = 0; i < DamageTypes::DamageTypes_Count; i ++ )
    {
        damageTypesChanger[i] = static_cast<DamageTypes>(i);
    }
}

ResultDamage SkillAttackResult::calculateDamage()
{
    float scale_damage = 0;
    scale_damage += _Damage.MWDamage.ScaleValue.at(0) * _Damage.MWDamage.ScaleAttribute[Strength];
    scale_damage += _Damage.MWDamage.ScaleValue.at(1) * _Damage.MWDamage.ScaleAttribute[Agility];
    scale_damage += _Damage.MWDamage.ScaleValue.at(2) * _Damage.MWDamage.ScaleAttribute[Intelligence];

    float damage = _Damage.MWDamage.damage + scale_damage;
    // calculate critical
    ResultDamage result;
    result.type.append(_Damage.MWDamage.Type);
    result.damage.append(damage);
    return result;
}


void SkillAttackResult::addNewCritical(float value, float chance)
{
    _criticalValue.append(value);
    _criticalChanse.append(chance);
}

void SkillAttackResult::changeTypeFromTo(DamageTypes from, DamageTypes to)
{
    damageTypesChanger[from] = to;
}
