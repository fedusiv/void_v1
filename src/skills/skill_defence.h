#ifndef SKILL_DEFENCE_H
#define SKILL_DEFENCE_H

#include "skill.h"
#include "skillattack.h"

class SkillDefence : public Skill
{
protected:
    SkillDefenceAttribure _AttributeDeffence;

    SkillFightChanger   _AttributeFight;

    void changeCritical(SkillAttackResult * attack);
public:
    SkillDefence(SkillDefenceAttribure attribute);
    void processDefence(SkillAttackResult * attack);
    void TranslateParameters() override;
};

#endif // SKILL_DEFENCE_H
