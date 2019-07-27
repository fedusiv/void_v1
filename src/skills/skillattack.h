#ifndef SKILLATTACK_H
#define SKILLATTACK_H

#include "skill.h"

class SkillAttackResult
{
private:

    QList<float> _criticalValue;
    QList<float> _criticalChanse;


    PlayerWeaponDamage _defaultDamage;
    WeaponHands _defaultHand;

    PlayerWeaponDamage  _Damage;
    WeaponHands         _Hand;

    ArmorValue _EnemyArmor;
    ResultDamage _ResultDamage;

    DamageTypes _damageTypesChanger[DamageTypes::DamageTypes_Count];

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
    struct values
    {
        criticalParam critical;

        float damagePrevConst;
        float damagePostConst;

        float damagePrevMulti;
        float damagePostMulti;

        MainStatsScale scaleValueMulti;
        MainStatsScale scaleValueConst;
        MainStatsScale statsValueMulti;
        MainStatsScale statsValueConst;
        WeaponHands hand;
        DamageTypes newType;
        DamageTypes fromType;
    }values;

public:
    SkillAttack(SkillAttackAttribure attribute);

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
