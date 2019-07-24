#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <QList>

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
    QList<MainStats> ScaleAttribute;
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
 * Struct holds information about Armor
 */
typedef struct ArmorValue
{
    float Armor;
    DamageTypes ArmorType;
}ArmorValue;

/*
 * List of All Classes in the game
 */
typedef enum ClassList
{
    Assassin,
    Rogue,
    Mage,
    Warrior,
    Knight,
    RaceCount
}ClassList;

#endif // COMMON_TYPES_H
