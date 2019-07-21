#include "skilllist.h"

SkillList::SkillList()
{

}

void SkillList::addNewSkill(Skill skill)
{
    _Skills.append(skill);
}
