#include "player.h"

Player::Player()
{
    _PlayerState = new PlayerState();
    _PlayerSkillsList = new SkillList();
    _PlayerSkillQueue = new SkillsQueue();
}

void Player::MakeWeaponHit()
{
    _PlayerState->getPlayerDamage();
}
