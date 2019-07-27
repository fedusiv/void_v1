#ifndef SKILL_H
#define SKILL_H
// TODO : add memory aligment to all struct with bit sets
#include <QString>
#include "skillvalues.h"
#include "skill_class_types.h"
#include "common_types.h"
#include "skills_description.h"

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
    int Lear;       // Here is information about Lear. In future must be changed from int to Lear Struct
    bool Active;
}SkillAttribute;

/*
 * struct holds info only accurate about skills attack type
 */
typedef struct SkillAttackAttribure
{
    SkillAttackAmp Type;
    SkillAttribute BaseAttribute;
}SkillAttackAttribure;

/*
 * struct holds info only accurate about skills attack type
 */
typedef struct SkillDefenceAttribure
{
    SkillDefenceAmp Type;
    SkillAttribute BaseAttribute;
}SkillDefenceAttribure;

class Skill
{

public:
    virtual ~Skill();
    Skill();// Use very carefully
    Skill(SkillAttribute attribute);
    int checkDuration();
protected:
    SkillAttribute _Attribute;

};
#endif //SKILL_H
