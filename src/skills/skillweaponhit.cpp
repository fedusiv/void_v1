#include "skillweaponhit.h"

SkillWeaponHit::SkillWeaponHit(PlayerWeaponDamage damage)
{
    _SkillTypesAttack = SkillTypesAttack::WeaponHit;
    _PlayerWeaponDamage = damage;
}
