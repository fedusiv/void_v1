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


    DamageTypes damageTypesChanger[DamageTypes::DamageTypes_Count];

public:
    // constructor for weapon style attack
    SkillAttackResult(PlayerWeaponDamage damage, WeaponHands hand);
    ResultDamage calculateDamage();
    void addNewCritical(float value, float chance);
    void changeTypeFromTo(DamageTypes from, DamageTypes to);
};



class SkillAttack : public Skill
{
protected:
    SkillAttackAttribure _AttributeAttack;
    // struct describe, what field must be changed
    struct values
    {
        float criticalValue;
        float criticalChanse;
        float damagePrevConst;
        float damagePostConst;
        float damagePrevMulti;
        float damagePostMulti;
        float scaleValueMulti;
        QVector<float> scaleValueConst;
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
};

#endif // SKILLATTACK_H
