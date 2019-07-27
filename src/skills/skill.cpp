#include "skill.h"


Skill::Skill(SkillAttribute attribute)
{
    _Attribute = attribute;
}

Skill::~Skill()
{

}

int Skill::checkDuration()
{
    if ( _Attribute.Duration.Forever)
        return 1;
    if ( _Attribute.Duration.Fight)
        return 1;
    if ( _Attribute.Duration.TillNextFight)
        return 1;
    if ( _Attribute.Duration.value - 1)
        return 1;

    return 0;
}
