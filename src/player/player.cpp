#include "player.h"

Player::Player()
{
    _PlayerState = new PlayerState();
    _PlayerSkillsList = new SkillList();
    _PlayerSkillQueue = new SkillsQueue();
    _Inventory = new Inventory();
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

EquipReturnCode Player::equipWeapon(ItemWeapon *weapon)
{
    EquipReturnCode res = weapon->checkRequirments(_PlayerState->getStatsForRequire());

    if ( res == EquipReturnCode::SUCCESS)
    {
        return _Inventory->equipMainWeapon(weapon);
    }
    else
    {
        return  res;
    }
}
