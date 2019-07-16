#ifndef SKILL_H
#define SKILL_H
// TODO : add memory aligment to all struct with bit sets
#include <QString>
#include "skillvalues.h"

// Common types of Skill
typedef enum SkillType
{
    Attack,                 // Change Attack parameters
    Take,                   // Some changes in processing damage
    Stats                   // All other
}SkillType;

// Information About Skill target
typedef enum SkillTarget
{
    Self,
    Enemy
}SkillTarget;

// stores information about Skill Type. And Type inside Class
typedef struct SkillAttributeType
{
    uint8_t SkillType:4;
    uint8_t ClassType:4;

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
    Skill(SkillAttribute attribute);


private:
    QString _Name;
    QString _Desc;
    SkillDurationInformation _Duration;
    SkillTarget _Target;
    SkillType _SkillType;
    SkillValues * _SkillValues;
    bool _Active;

};
#endif //SKILL_H
