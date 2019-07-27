#ifndef SKILLATTACK_H
#define SKILLATTACK_H

#include "skill.h"
#include "skillvalues.h"
class SkillAttackResult
{
private:

    QList<criticalParam> _critical;

    PlayerMagicDamage _defaultMagicDamage;

    PlayerWeaponDamage _defaultDamage;
    WeaponHands _defaultHand;

    PlayerMagicDamage   _DamageMagic;
    PlayerWeaponDamage  _Damage;
    WeaponHands         _Hand;

    ArmorValue _EnemyArmor;
    ResultDamage _ResultDamage;

    DamageTypes _damageTypesChanger[DamageTypes::DamageTypes_Count];
    DamageTypes _armorTypesChanger[DamageTypes::DamageTypes_Count];

    EvasionValue _evasionSelf;
    EvasionValue _evasionEnemy;

    float criticalCalculate();
    void reduceDamageOfArmor();
public:
    // constructor for weapon style attack
    SkillAttackResult(PlayerWeaponDamage damage, WeaponHands hand);
    void calculateBefore();     // calculations before send attack to enemy
    float calculateFinal();      // calculations to make damage to Health

    void addNewCritical(criticalParam critical);
    void reduceAllCritical(criticalParam critical);
    void changeTypeFromTo(DamageTypes from, DamageTypes to);
    void changeWeaponDamage(float constant, float multi);
    void addHandHit();
    void changeScaleValue(MainStatsScale constant, MainStatsScale multi);
    void changeStatsValue(MainStatsScale constant, MainStatsScale multi);

};



class SkillAttack : public Skill
{
protected:
    SkillAttackAttribure _AttributeAttack;
    // struct describe, what field must be changed
    SkillFightChanger   _AttributeFight;

public:
    SkillAttack(SkillAttackAttribure attribute);
    void TranslateParameters() override;
    void processAttack(SkillAttackResult * attack);
private:
    void processCritical(SkillAttackResult * attack);
    void ChangeTypeFromTo(SkillAttackResult * attack);
    void AddHandHit(SkillAttackResult * attack);
    void changeWeaponDamage(SkillAttackResult * attack);
    void changeScaleValue(SkillAttackResult * attack);
    void changeStatsValue(SkillAttackResult * attack);
};

#endif // SKILLATTACK_H
