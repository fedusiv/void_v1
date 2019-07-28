#ifndef SKILL_H
#define SKILL_H
// TODO : add memory aligment to all struct with bit sets
#include <QString>
#include <QVector>
#include "skillvalues.h"
#include "skill_class_types.h"
#include "common_types.h"
#include "skills_description.h"
#include "lear/class_list.h"

// Common types of Skill
typedef enum SkillType
{
    Attack,                 // Change Attack parameters
    Defence,                   // Some changes in processing damage
    Common                   // All other
}SkillType;

// Information About Skill target
typedef enum SkillTarget
{
    Self,
    Enemy
}SkillTarget;

// all information about skills duration
typedef struct  SkillDurationInformation
{
    bool Forever;
    bool Fight;
    bool TillNextFight;
    int value;
}SkillDurationInformation;

/*
 * struct, which stores data of skill. More convient for Skill constructor
 * struct for dataBase
 */
typedef struct  SkillAttribute
{
    QString id;     // id of Skill
    QString name;   // Name of Skill
    QString desc;   // Description
    SkillDurationInformation duration;  // information about skill duration
    SkillTarget target; // Tell what is the target of Skill
    SkillType skillType;   // information about all types of skill
    Lear learName;
    SkillClassTypes classType;  // inforamtion about skill type
    bool active;
}SkillAttribute;

/*
 * struct holds info only accurate about skills attack type
 */
typedef struct SkillAttackAttribure
{
    QVariantMap values;
    SkillAttackAmp type;
    SkillAttribute baseAttribute;
}SkillAttackAttribure;

/*
 * struct holds info only accurate about skills attack type
 */
typedef struct SkillDefenceAttribure
{
    QVariantMap values;
    SkillDefenceAmp type;
    SkillAttribute baseAttribute;
}SkillDefenceAttribure;

/*
 * Struct describes all changers in Fight parameters
 */
typedef struct SkillFightChanger
{
    criticalParam critical;
    criticalParam criticalMagic;

    float damageWeaponConst;
    float damageWeaponMulti;

    float damageMagicConst;
    float damageMagicMulti;

    float damagePostConst;
    float damagePostMulti;

    MainStatsScale scaleValueMulti;
    MainStatsScale scaleValueConst;

    MainStatsScale statsValueMulti;
    MainStatsScale statsValueConst;

    WeaponHands hand;

    DamageTypes newAttackType;
    DamageTypes fromAttackType;

    DamageTypes newArmorType;
    DamageTypes fromArmorType;

    EvasionValue evasion;

}SkillFightChanger;


class Skill
{

public:
    virtual ~Skill();
    Skill() // Use very carefully
    {
        // I had to implement default constructor
        // because otherwise SkillWeaponHit throws unresolved external
        // now i can see what is "Use very carefully" :)
    }

    Skill(SkillAttribute attribute);
    virtual void TranslateParameters() {}
    int checkDuration();
protected:
    SkillAttribute _Attribute;

};
#endif //SKILL_H
