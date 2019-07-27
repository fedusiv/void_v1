#ifndef SKILL_DEFENCE_H
#define SKILL_DEFENCE_H

#include "skill.h"
#include "skillattack.h"

class SkillDefence : public Skill
{
protected:
    SkillDefenceAttribure _AttributeDeffence;

    struct values
    {
        criticalParam critical;

        float damagePrevConst;
        float damagePrevMulti;

        float damagePostConst;
        float damagePostMulti;

        MainStatsScale scaleValueMulti;
        MainStatsScale scaleValueConst;

        MainStatsScale statsValueMulti;
        MainStatsScale statsValueConst;

        WeaponHands handRemove;

        DamageTypes newArmorType;
        DamageTypes fromArmorType;

        DamageTypes newWeaponType;
        DamageTypes fromWeaponType;
    }values;

    void changeCritical(SkillAttackResult * attack);
public:
    SkillDefence(SkillDefenceAttribure attribute);
    void processDefence(SkillAttackResult * attack);
};

#endif // SKILL_DEFENCE_H
