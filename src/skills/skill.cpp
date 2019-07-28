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
    if ( _Attribute.duration.Forever)
        return 1;
    if ( _Attribute.duration.Fight)
        return 1;
    if ( _Attribute.duration.TillNextFight)
        return 1;
    if ( _Attribute.duration.value - 1)
        return 1;

    return 0;
}
