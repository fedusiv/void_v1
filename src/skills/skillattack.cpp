#include "skillattack.h"

SkillAttack::SkillAttack(SkillAttackAttribure attribute) : Skill (attribute.BaseAttribute )
{
    _AttributeAttack = attribute;
}


void SkillAttack::processAttack(SkillAttackResult * attack)
{
    switch (_AttributeAttack.Type)
    {
    case SkillAttackAmp::Critical:
        processCritical(attack);
    break;
    case SkillAttackAmp::ChangeTypeFromTo:
        ChangeTypeFromTo(attack);
    break;
    case SkillAttackAmp::AddHandHit:
        AddHandHit(attack);
    break;
    case SkillAttackAmp::ChangeWeaponDamage:
        changeWeaponDamage(attack);
    break;
    case SkillAttackAmp::ChangeScaleValue:
        changeScaleValue(attack);
    break;
    case SkillAttackAmp::ChangeStats:
        changeStatsValue(attack);
    break;
    default:
        break;
    }
}

void SkillAttack::processCritical(SkillAttackResult *attack)
{
    attack->addNewCritical(values.critical);
}

void SkillAttack::ChangeTypeFromTo(SkillAttackResult *attack)
{
    attack->changeTypeFromTo(values.fromType, values.newType);
}

void SkillAttack::AddHandHit(SkillAttackResult *attack)
{
    attack->addHandHit();
}

void SkillAttack::changeWeaponDamage(SkillAttackResult *attack)
{
    attack->changeWeaponDamage(values.damagePrevConst, values.damagePrevMulti);
}

void SkillAttack::changeScaleValue(SkillAttackResult *attack)
{
    attack->changeScaleValue(values.scaleValueConst, values.scaleValueMulti);
}

void SkillAttack::changeStatsValue(SkillAttackResult *attack)
{
    attack->changeStatsValue(values.statsValueConst, values.statsValueMulti);
}





float SkillAttackResult::criticalCalculate()
{
    return 1.0;
}

SkillAttackResult::SkillAttackResult(PlayerWeaponDamage damage, WeaponHands hand)
{
    _defaultDamage = damage;
    _Damage = _defaultDamage;
    _defaultHand = hand;
    for ( int i = 0; i < DamageTypes::DamageTypes_Count; i ++ )
    {
        _damageTypesChanger[i] = static_cast<DamageTypes>(i);
    }
}

void SkillAttackResult::calculateBefore()
{
    // change weapon damage type
    _Damage.MWDamage.Type = _damageTypesChanger[_Damage.MWDamage.Type];
    _Damage.SWDamage.Type = _damageTypesChanger[_Damage.SWDamage.Type];
}

float SkillAttackResult::calculateFinal()
{
    // change weapon damage type
    _Damage.MWDamage.Type = _damageTypesChanger[_Damage.MWDamage.Type];
    _Damage.SWDamage.Type = _damageTypesChanger[_Damage.SWDamage.Type];

    // count damage from weapon
    switch (_Hand) {
        case WeaponHands::Main:
    {
        _ResultDamage.damage[_Damage.MWDamage.Type] +=
               ( _Damage.MWDamage.damage + _Damage.MWDamage.ScaleValue.calculate(_Damage.MWDamage.ScaleAttribute) )
                * criticalCalculate();
    }
        break;
    case WeaponHands::Second:
    {
        _ResultDamage.damage[_Damage.SWDamage.Type] +=
               ( _Damage.SWDamage.damage + _Damage.SWDamage.ScaleValue.calculate(_Damage.SWDamage.ScaleAttribute) )
                 * criticalCalculate();
    }
    break;
    case WeaponHands::Both:
    {
        _ResultDamage.damage[_Damage.MWDamage.Type] +=
               ( _Damage.MWDamage.damage + _Damage.MWDamage.ScaleValue.calculate(_Damage.MWDamage.ScaleAttribute) )
                * criticalCalculate();
        _ResultDamage.damage[_Damage.SWDamage.Type] +=
               ( _Damage.SWDamage.damage + _Damage.SWDamage.ScaleValue.calculate(_Damage.SWDamage.ScaleAttribute) )
                 * criticalCalculate();
    }
    break;
    case WeaponHands::None:
        break;
    }

    reduceDamageOfArmor();
    float _result = 0.0;
    for ( int i = 0; i < DamageTypes::DamageTypes_Count; i++)
    {
        _result += _ResultDamage.damage[i];
    }

    return  _result;
}

/*
 * Calculate result damage after armor influence
 */
void SkillAttackResult::reduceDamageOfArmor()
{

}

void SkillAttackResult::addNewCritical(criticalParam critical)
{
    _criticalValue.append(critical.value);
    _criticalChanse.append(critical.chance);
}

void SkillAttackResult::reduceAllCritical(criticalParam critical)
{
    for ( int i = 0; i < _criticalValue.size(); i ++)
    {
        _criticalValue[i]-=critical.value;
    }

    for ( int i = 0; i < _criticalChanse.size(); i ++)
    {
        _criticalChanse[i]-=critical.chance;
    }

}

void SkillAttackResult::changeTypeFromTo(DamageTypes from, DamageTypes to)
{
    _damageTypesChanger[from] = to;
}

void SkillAttackResult::changeWeaponDamage(float constant, float multi)
{
    _Damage.MWDamage.damage += constant;
    _Damage.SWDamage.damage += constant;

    _Damage.MWDamage.damage += _Damage.MWDamage.damage * multi;
    _Damage.SWDamage.damage += _Damage.SWDamage.damage * multi;

}

void SkillAttackResult::addHandHit()
{
    _Hand = WeaponHands::Both;
}

void SkillAttackResult::changeScaleValue(MainStatsScale constant, MainStatsScale multi)
{
    _Damage.MWDamage.ScaleValue.Strength += constant.Strength;
    _Damage.MWDamage.ScaleValue.Agility += constant.Agility;
    _Damage.MWDamage.ScaleValue.Intelligence += constant.Intelligence;

    _Damage.MWDamage.ScaleValue.Strength        +=    _Damage.MWDamage.ScaleValue.Strength * multi.Strength;
    _Damage.MWDamage.ScaleValue.Agility         +=    _Damage.MWDamage.ScaleValue.Agility *  multi.Agility;
    _Damage.MWDamage.ScaleValue.Intelligence    +=    _Damage.MWDamage.ScaleValue.Agility * multi.Intelligence;

}

void SkillAttackResult::changeStatsValue(MainStatsScale constant, MainStatsScale multi)
{
    _Damage.MWDamage.ScaleAttribute.Strength += constant.Strength;
    _Damage.MWDamage.ScaleAttribute.Agility += constant.Agility;
    _Damage.MWDamage.ScaleAttribute.Intelligence += constant.Intelligence;

    _Damage.MWDamage.ScaleAttribute.Strength        +=    _Damage.MWDamage.ScaleAttribute.Strength * multi.Strength;
    _Damage.MWDamage.ScaleAttribute.Agility         +=    _Damage.MWDamage.ScaleAttribute.Agility *  multi.Agility;
    _Damage.MWDamage.ScaleAttribute.Intelligence    +=    _Damage.MWDamage.ScaleAttribute.Agility * multi.Intelligence;

}
