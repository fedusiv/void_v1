#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

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

/*
 * Struct stores inforamation about Player's damage from weapon
 */
typedef struct PlayerWeaponDamage
{
    DamageTypes MWDamageType;   // Main Weapon
    float       MWDamage;
    DamageTypes SWDamageType;   // Second Weapon
    float       SWDamage;
    int amout;                  // all amount of weapons

}PlayerWeaponDamage;

/*
 * List of All Race in the game
 */
typedef enum RaceList
{
    Assassin,
    Rogue,
    Mage,
    Warrior,
    Knight,
    RaceCount
}RaceList;

#endif // COMMON_TYPES_H
