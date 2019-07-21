#ifndef SKILLLIST_H
#define SKILLLIST_H

#include <QList>
#include "skill.h"

/*
 * Object stores all Skill, which Player has
 */
class SkillList
{
private:
    QList<Skill> _Skills;

public:
    SkillList();
    QList<Skill> getAllSkills(){return _Skills;}
    void addNewSkill(Skill skill);
};

#endif // SKILLLIST_H
