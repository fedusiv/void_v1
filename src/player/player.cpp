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

EquipReturnCode Player::equipItem(Item * item)
{
    Q_UNUSED( item);
    return  EquipReturnCode::Other;
}

EquipReturnCode Player::equipCloth(ItemCloth * cloth)
{
    // QUESTION: HOW TO SELECT WEAPON IN GUI
    EquipReturnCode res = cloth->checkRequirments(_PlayerState->getStatsForRequire());

    if ( res == EquipReturnCode::SUCCESS)
    {
        return _Inventory->equipCloth(cloth); //QUSTION: replaced it from equipMainWeapon(), how so?
    }
    else
    {
        return  res;
    }
}

EquipReturnCode Player::equipWeapon(ItemWeapon * weapon)
{
    // QUESTION: HOW TO SELECT WEAPON IN GUI
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
