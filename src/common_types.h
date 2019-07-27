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
 * Struct stores scales values
 */
typedef struct MainStatsScale
{
    float Strength;
    float Agility;
    float Intelligence;
    float calculate(MainStats stats)
    { float res = 0.0;
      res+=Strength * stats.Strength;
      res+=Agility * stats.Agility;
      res+=Intelligence * stats.Intelligence;
      return  res;}
}MainStatsScale;

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
enum class WeaponHands
{
    Main,
    Second,
    Both,
    None
};

/*
 * Describe the damage property of weapon
 */
typedef struct ItemWeaponDamage
{
    float damage;
    DamageTypes Type;
    MainStatsScale ScaleValue;
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
    float damage[DamageTypes::DamageTypes_Count];
}ResultDamage;

/*
 * Struct holds information about Armor
 */
typedef struct ArmorValue
{
    float armor[DamageTypes::DamageTypes_Count];
}ArmorValue;


typedef struct criticalParam
{
    float value;
    float chance;
}criticalParam;

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
