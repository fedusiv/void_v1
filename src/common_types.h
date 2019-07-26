#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <QList>
#include <QVector>


/*
 * Struct stores Data about requirments for Items or Skills
 */
typedef struct MainStatsRequire
{
    int Strength;
    int Agility;
    int Intelligence;
    int Level;
}StatsRequire;

//SUGGESTION:
/* maybe do this:

enum StatsKeys {Strength, Agility, Intelligence, Level, StatsCount};
typedef int StatsRequire[StatsCount];

 * and when you need stat, you get it like this:
 * StatsRequire stats;
 * int str = stats[Strength];
 */

/*
 * Struct stores Main PLayer's Stats type
 */
typedef struct MainStats
{
    int Strength;
    int Agility;
    int Intelligence;
}MainStats;

/*
 * List of Damage and Armor types in the game
 */
typedef enum DamageTypes
{
    Metal,
    Elementary,
    Composite,
    Arcane,
    Blood,
    DamageTypes_Count
}DamageTypes;

/*
 * In what hand Weapon
 */
typedef enum WeaponHands
{
    Main,
    Second,
    Both
}WeaponHands;

/*
 * Describe the damage property of weapon
 */
typedef struct ItemWeaponDamage
{
    float damage;
    DamageTypes Type;
    QList<float> ScaleValue;
    MainStats ScaleAttribute;
    WeaponHands Hand;
}ItemWeaponDamage;

/*
 * Struct stores inforamation about Player's damage from weapon
 */
typedef struct PlayerWeaponDamage
{
    ItemWeaponDamage       MWDamage;
    ItemWeaponDamage       SWDamage;
}PlayerWeaponDamage;

/*
 * Result, what affect to target
 */
typedef struct ResultDamage
{
    QVector<float> damage;
    QVector<DamageTypes> type;
}ResultDamage;

/*
 * Struct holds information about Armor
 */
typedef struct ArmorValue
{
    float Armor;
    DamageTypes ArmorType;
}ArmorValue;


#endif // COMMON_TYPES_H
