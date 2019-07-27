#ifndef SKILLSQUEUE_H
#define SKILLSQUEUE_H

#include <QList>
#include <QStack>
#include "skill.h"
#include "skillweaponhit.h"
#include "skillattack.h"
#include "skill_defence.h"
#include <QSharedPointer>
/*
 * Object operate with Skills Queue
 */
class SkillsQueue
{
private:

    QList<SkillAttack * > _AttackQueue;
    QList<SkillDefence*> _DefenceQueue;
    QList<Skill*> _CommonQueue;

    QStack<Skill*> _Stack;

    void putQueueToStack(QList<Skill*> queue);
public:
    SkillsQueue();
    SkillAttackResult* makeWeaponHit(PlayerWeaponDamage damage , WeaponHands hand);
    float DefenceFromWeaponHit(SkillAttackResult  * attack);
};

#endif // SKILLSQUEUE_H
