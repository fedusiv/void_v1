#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <QVector>
#include "common_types.h"

/*
 * Player State object holds information about Player parameters
 */
class PlayerState
{

private:
    MainStats _MainStats;   // Main 3 Parameters
    float _Health;          // Current Health of Player
    float _HealthMax;       // Maximum value of Health
    float _InventoryWeight; // Maximum carrying power of Player
    int _Level;             // Current level of PLayer
    int _Step;              // Current Step
    QVector<int> _Armor;    // Armor parameters of Player
    PlayerWeaponDamage _PlayerWeaponDamage;
    QVector<int> RaseSets;  //set of Race's which Player stores

    // methods part
    void firstInitilize();

public:
    PlayerState();
    void setHealth(float health);
    void setHealthMax(float health);
    float getHealth() { return _Health;}
    float getHealthMax() {return _HealthMax;}

};

#endif // PLAYERSTATE_H
