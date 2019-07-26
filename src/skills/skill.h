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
    // REMOVE Values
    LearClassList Lear;       // Here is information about Lear. In future must be changed from int to Lear Struct
    bool Active;
}SkillAttribute;

/*
 * struct holds info only accurate about skills attack type
 */
typedef struct SkillAttackAttribure
{
    QVector<float> Values;
    SkillAttackAmp Type;
    SkillAttribute BaseAttribute;
}SkillAttackAttribure;

class Skill
{

public:
    virtual ~Skill();
    Skill();// Use very carefully
    Skill(SkillAttribute attribute);
    // method for Change Damage
    // method for Change Defence

protected:
    QString _Name;
    QString _Desc;
    SkillDurationInformation _Duration;
    SkillTarget _Target;
    SkillType _SkillType;
    //SkillValues * _SkillValues;
    SkillClassTypes _ClassType;
    bool _Active;

};
#endif //SKILL_H
