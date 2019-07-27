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

// Forming attack on WeaponHit
SkillAttackResult* SkillsQueue::makeWeaponHit(PlayerWeaponDamage damage, WeaponHands hand)
{

    SkillAttackResult * attack = new SkillAttackResult(damage, hand);
    for( SkillAttack * skill : _AttackQueue)
    {
        skill->processAttack(attack);
        if ( skill->checkDuration() )
            _AttackQueue.removeOne(skill);//  TODO: REMOVE AFTER USE
    }
    attack->calculateBefore();   // calculate all damage and ready to send to Enemy
    return attack;
}

// Defence from WeaponHit
float SkillsQueue::DefenceFromWeaponHit(SkillAttackResult * attack)
{
    for( SkillDefence * skill : _DefenceQueue)
    {
        skill->processDefence(attack);
        if ( skill->checkDuration() )
            _DefenceQueue.removeOne(skill);//  TODO: REMOVE AFTER USE
    }

    return attack->calculateFinal();    // get float value of Health loose
}
