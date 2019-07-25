#ifndef SKILLSQUEUE_H
#define SKILLSQUEUE_H

#include <QList>
#include <QStack>
#include "skill.h"
#include "skillweaponhit.h"
#include "skillattack.h"
/*
 * Object operate with Skills Queue
 */
class SkillsQueue
{
private:

    QList<SkillAttack * > _AttackQueue;
    QList<Skill*> _DefenceQueue;
    QList<Skill*> _CommonQueue;

    QStack<Skill*> _Stack;

    void putQueueToStack(QList<Skill*> queue);
public:
    SkillsQueue();
    ResultDamage makeWeaponHit(PlayerWeaponDamage damage , WeaponHands hand);
};

#endif // SKILLSQUEUE_H
