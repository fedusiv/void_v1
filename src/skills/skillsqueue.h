#ifndef SKILLSQUEUE_H
#define SKILLSQUEUE_H

#include <QList>
#include "skill.h"
/*
 * Object operate with Skills Queue
 */
class SkillsQueue
{
private:

    QList<Skill> _AttackQueue;
    QList<Skill> _DefenceQueue;
    QList<Skill> _CommonQueue;

public:
    SkillsQueue();
};

#endif // SKILLSQUEUE_H
