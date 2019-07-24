#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <QVector>
#include <QMap>
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
    int _Level;             // Current level of Player
    int _Step;              // Current Step
    QVector<float> _Armor;    // Armor parameters of Player
    PlayerWeaponDamage _PlayerWeaponDamage; // damage from weapon
    QMap<ClassList,int> _LearState;  //set of Classes's which Player stores

    // methods part
    void firstInitilize();

public:
    PlayerState();                              // constructor

    void setHealth(float health);               // setter of Health
    void setHealthMax(float health);            // setter of Health Max
    float getHealth() { return _Health;}        // get Health
    float getHealthMax() {return _HealthMax;}   // get max Health

    void  setInventoryWeight(float weight){_InventoryWeight = weight;}
    float getInventoryWeight(){return _InventoryWeight;}

    void setLevel(int level){_Level = level;}
    int  getLevel(){return _Level;}

    void setStep(int step){_Step = step;}
    int  getStep(){return _Step;}

    void changeArmor(DamageTypes damageType, float value);
    QVector<float> getArmor(){return _Armor;}           // return Armor parameter

    void changeLearParameter(ClassList playerClass, int value);   // change one parametr of Lear state
    QMap<ClassList, int> getLearState() { return _LearState;}// return Lear State of Player

    void setWeaponDamage(ItemWeaponDamage itemDamage);      // sets playerweapondamage, must be called from inventory.
    PlayerWeaponDamage getPlayerDamage();

};

#endif // PLAYERSTATE_H
