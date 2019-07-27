#ifndef SKILLS_DESCRIPTION_H
#define SKILLS_DESCRIPTION_H

/*
 * Types of attack skills
 */
enum class SkillAttackAmp
{
    Critical,
    ChangeTypeFromTo,
    AddHandHit,
    ChangeWeaponDamage,
    ChangeScaleValue,
    ChangeStats,

    SkillAttackAmpCount
};

/*
 * Types of Defence skills
 */
enum class SkillDefenceAmp
{
    Critical,
    ChangeArmorTypeFromTo,
    ChangeArmorValue,
    RemoveHandHit,
    ChangeWeaponDamage,
    ChangeScaleValue,
    ChangeStats,

    SkillDefenceAmpCount
};

#endif // SKILLS_DESCRIPTION_H
