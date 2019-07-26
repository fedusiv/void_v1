#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <QList>
#include <QVector>

/*
 * Type stores Main PLayer's Stats type
 * use it like this:
 *
 * MainStats mstats_;
 * int str = mstats_[Strength];
 */
enum MainStatNames
{
    Strength,
    Agility,
    Intelligence,
    MainStatsCount
};

typedef int MainStats[MainStatsCount];


/*
 * Type stores Data about requirments for Items or Skills
 * store same values as MainStats + Level
 * use it like MainStats
 */
enum RequireStatNames
{
    Level = Intelligence + 1,
    RequireStatsCount
};

typedef int StatsRequire[RequireStatsCount];

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
