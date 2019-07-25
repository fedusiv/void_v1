#include "skillsqueue.h"

SkillsQueue::SkillsQueue()
{

}


void SkillsQueue::putQueueToStack(QList<Skill *> queue)
{
    for ( auto skill : queue )
    {
        _Stack.push(skill);
    }
}

ResultDamage SkillsQueue::makeWeaponHit(PlayerWeaponDamage damage, WeaponHands hand)
{

    SkillAttackResult * attack = new SkillAttackResult(damage, hand);
    for( SkillAttack * skill : _AttackQueue)
    {
        skill->processAttack(attack);
    }

    return attack->calculateDamage();
}
