#ifndef SKILLWEAPONHIT_H
#define SKILLWEAPONHIT_H

#include "skill.h"

class SkillWeaponHit : public Skill
{
private:
    PlayerWeaponDamage _PlayerWeaponDamage;
public:
    SkillWeaponHit(PlayerWeaponDamage damage);
};

#endif // SKILLWEAPONHIT_H
