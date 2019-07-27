#include "skill_defence.h"


SkillDefence::SkillDefence(SkillDefenceAttribure attribute)
{
    _AttributeDeffence = attribute;
}

void SkillDefence::processDefence(SkillAttackResult * attack)
{
    switch (_AttributeDeffence.Type)
    {
    case SkillDefenceAmp::Critical:
        changeCritical(attack);
    break;
    default:
        break;
    }
}


void SkillDefence::changeCritical(SkillAttackResult * attack)
{

}
