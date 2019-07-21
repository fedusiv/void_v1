#include "playerstate.h"
/*
 * @desc : This method initilize all parameters of player to default values in the start
 */
void PlayerState::firstInitilize()
{
    // TODO : make some keeper to keep default start Player parameters

    _MainStats.Strength = 1;
    _MainStats.Agility = 1;
    _MainStats.Intelligence = 1;
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

void PlayerState::changeLearParameter(ClassList playerClass, int value)
{
    _LearState.insert(playerClass,value);
}
