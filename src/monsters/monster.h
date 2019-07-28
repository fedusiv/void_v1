#ifndef MONSTER_H
#define MONSTER_H

#include <QString>
#include <QList>
#include "common_types.h"
#include "skills/skilllist.h"
#include "skills/skillsqueue.h"
#include "return_codes.h"

struct MonsterAttribute
{
    QString name;                   // name of monster
    QString desc;                   // Lore description
    QString picture;                // image of monster
    PlayerWeaponDamage damageStruct;// description of standart damage
    WeaponHands Hand;
    SkillList skillsList;
    // Combinations
    int level;
    float health;
    ArmorValue armor;
    //Rules for using weapon skills and combinations
    QMap<float,QString> loot;   // loot
    float experience;
};


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
