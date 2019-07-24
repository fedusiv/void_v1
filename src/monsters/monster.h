#ifndef MONSTER_H
#define MONSTER_H

#include <QString>
#include <QList>
#include "common_types.h"
#include "skills/skilllist.h"
#include "skills/skillsqueue.h"

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
public:
    Monster(MonsterAttribute attribute);
};

#endif // MONSTER_H
