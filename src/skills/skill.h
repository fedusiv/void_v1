#ifndef SKILL_H
#define SKILL_H
// TODO : add memory aligment to all struct with bit sets
#include <QString>
#include "skillvalues.h"
#include "skill_class_types.h"
#include "common_types.h"

// Common types of Skill
typedef enum SkillType
{
    Attack,                 // Change Attack parameters
    Defence,                   // Some changes in processing damage
    Common                   // All other
}SkillType;

// Common types of Skill
typedef enum SkillTypesAttack
{
    WeaponHit,                 // Weapon hit make form as Skill
    Count
}SkillTypesAttack;


// Information About Skill target
typedef enum SkillTarget
{
    Self,
    Enemy
}SkillTarget;

// stores information about Skill Type. And Type inside Class
typedef struct SkillAttributeType
{
    uint8_t SkillType:3;
    uint8_t ClassType:5;

}SkillAttributeType;

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
    QString Name;   // Name of Skill
    QString Desc;   // Description
    SkillDurationInformation Duration;  // information about skill duration
    SkillTarget Target; // Tell what is the target of Skill
    SkillAttributeType SkillType;   // information about all types of skill
    uint32_t Values; // it is 32 bit's for storing all required digital values
    int Lear;       // Here is information about Lear. In future must be changed from int to Lear Struct
    bool Active;
}SkillAttribute;


class Skill
{

public:
    Skill();//Use only with inherited! be sure this is constructor doesn't setup correctly settings.
    Skill(SkillAttribute attribute);
    // method for Change Damage
    // method for Change Defence
    SkillTypesAttack getSkillTypesAttack();
protected:
    QString _Name;
    QString _Desc;
    SkillDurationInformation _Duration;
    SkillTarget _Target;
    SkillType _SkillType;
    SkillValues * _SkillValues;
    SkillClassTypes _ClassType;
    bool _Active;

    SkillTypesAttack _SkillTypesAttack;
};
#endif //SKILL_H
