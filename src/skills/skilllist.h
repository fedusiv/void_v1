#ifndef SKILLLIST_H
#define SKILLLIST_H

#include <QVector>
#include "skill.h"

/*
 * Object stores all Skill, which Player has
 */
class SkillList
{
private:
    QVector<Skill> _Skills;

public:
    SkillList();
    QVector<Skill> getAllSkills(){return _Skills;}
    void addNewSkill(Skill skill);
};

#endif // SKILLLIST_H
