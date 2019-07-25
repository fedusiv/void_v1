#include "player.h"

Player::Player()
{
    _PlayerState = new PlayerState();
    _PlayerSkillsList = new SkillList();
    _PlayerSkillQueue = new SkillsQueue();
}

ResultDamage Player::MakeWeaponHit(WeaponHands hand)
{
   PlayerWeaponDamage damage =  _PlayerState->getPlayerDamage();    // get damage of all two hands
   return _PlayerSkillQueue->makeWeaponHit(damage, hand);           // put this damage to skill processing and return just simple result
}
