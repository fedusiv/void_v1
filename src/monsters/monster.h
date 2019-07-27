#ifndef MONSTER_H
#define MONSTER_H

#include <QString>
#include <QList>
#include "common_types.h"
#include "skills/skilllist.h"
#include "skills/skillsqueue.h"
#include "return_codes.h"

typedef struct MonsterAttribute
{
    QString Name;                   // name of monster
    QString Desc;                   // Lore description
    QString Picture;                // image of monster
    PlayerWeaponDamage DamageStruct;// description of standart damage
    WeaponHands Hand;
    SkillList SkillsList;
    // Combinations
    int Level;
    float Health;
    ArmorValue Armor;
    //Rules for using weapon skills and combinations
}MonsterAttribute;


class Monster
{
protected:
    MonsterAttribute _Attribute;
    SkillsQueue * _SkillQueue;
    FighterLiveStatus reduceHealth(float value);
public:
    Monster(MonsterAttribute attribute);
    FighterLiveStatus defencePhaseFromWeaponHit(SkillAttackResult * attack);
    SkillAttackResult * attackPhase();
};

#endif // MONSTER_H
