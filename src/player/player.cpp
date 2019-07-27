#include "player.h"

Player::Player()
{
    _PlayerState = new PlayerState();
    _PlayerSkillsList = new SkillList();
    _PlayerSkillQueue = new SkillsQueue();
}

void Player::MakeWeaponHit(WeaponHands hand)
{
   PlayerWeaponDamage damage =  _PlayerState->getPlayerWeaponDamage();    // get damage of all two hands
   emit _PlayerSkillQueue->makeWeaponHit(damage, hand);           // put this damage to skill processing and return just simple result
}

FighterLiveStatus Player::defenceFromMonster(SkillAttackResult *attack)
{
    return  _PlayerState->reduceHealth( _PlayerSkillQueue->DefenceFromWeaponHit(attack));
}
