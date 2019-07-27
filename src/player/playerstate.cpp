#include "playerstate.h"
/*
 * @desc : This method initilize all parameters of player to default values in the start
 */
void PlayerState::firstInitilize()
{
    // TODO : make some keeper to keep default start Player parameters

    _MainStats[Strength] = 1;
    _MainStats[Agility] = 1;
    _MainStats[Intelligence] = 1;
    _HealthMax = 50;
    _Health = _HealthMax;
    _Level = 1;
    _Step = 0;
    // set Armor to Player
    for ( int i = 0; i < DamageTypes::DamageTypes_Count; i++)
    {
        _Armor.insert(i, 0);
    }
}

PlayerState::PlayerState()
{
    firstInitilize();   // init parameters
}

void PlayerState::setHealth(float health)
{
    if( health > _HealthMax)
    {
       _Health = _HealthMax;
    }
    else
    {
        _Health = health;
    }
}

void PlayerState::setHealthMax(float health)
{
    _HealthMax = health;
}

/*
 * @desc : change one of the Armor parameters
 * @param: damage Type
 * @param : new value of Armor
 */
void PlayerState::changeArmor(DamageTypes damageType, float value)
{
    _Armor[damageType] = value;
}

void PlayerState::changeLearParameter(Lear playerClass, int value)
{
    _LearState.insert(playerClass,value);
}

void PlayerState::setWeaponDamage(ItemWeaponDamage itemDamage)
{
    if ( itemDamage.Hand != WeaponHands::Second )
    {
        _PlayerWeaponDamage.MWDamage = itemDamage;
    }else
    {
        _PlayerWeaponDamage.SWDamage = itemDamage;
    }
}

PlayerWeaponDamage PlayerState::getPlayerDamage()
{
    // BE CARE! Inside inventory and item, main stats shows just whicj main stats are using, 0 and 1
    // Out in skills and player state, they multiply according to Main Stats
    _PlayerWeaponDamage.MWDamage.ScaleAttribute[Strength] *= _MainStats[Strength];
    _PlayerWeaponDamage.MWDamage.ScaleAttribute[Agility] *= _MainStats[Agility];
    _PlayerWeaponDamage.MWDamage.ScaleAttribute[Intelligence] *= _MainStats[Intelligence];

    return _PlayerWeaponDamage;
}
