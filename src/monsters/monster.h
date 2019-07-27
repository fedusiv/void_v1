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
    SkillList SkillsList;
    // Combinations
    int Level;
    float Health;
    QList<ArmorValue> Armor;
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
    void defencePhaseFromWeaponHit(SkillAttackResult * attack);
};

#endif // MONSTER_H
