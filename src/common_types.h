#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <QList>
#include <QVector>

#include <commonmacros.h>

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

struct MainStats
{
    int stats[MainStatsCount];

    inline int& operator[](int statId) { return stats[statId]; }
    static constexpr size_t size() { return MainStatsCount; }
};

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

struct StatsRequire
{
    int stats[RequireStatsCount];

    inline int& operator[](size_t statId) { return stats[statId]; }
    static constexpr size_t size() { return RequireStatsCount; }
};

/*
 * Struct stores scales values
 */
 struct MainStatsScale
{
    float scaleStats[MainStatsCount];

    inline float& operator[](int statId) { return scaleStats[statId]; }
    static constexpr size_t size() { return RequireStatsCount; }

    float calculate(MainStats stats)
    {
      float res = 0.0;
      for(int stat = 0; stat < MainStatsCount; stat++)
      {
          res += stats[stat] * scaleStats[stat];
      }

      return  res;
    }
};

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
    TwoHanded,
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
 * Struct stores inforamation about Player's damage from magic
 */
typedef struct PlayerMagicDamage
{
    float damage;
    DamageTypes Type;
    MainStatsScale ScaleValue;
    MainStats ScaleAttribute;
}PlayerMagicDamage;


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


/*
 * Struct holds information about Evasion chance
 */
typedef struct EvasionValue
{
    float evasion[DamageTypes::DamageTypes_Count];
}EvasionValue;

typedef struct criticalParam
{
    float value;
    float chance;
    void reduce(criticalParam cr){ value-=cr.value; chance-=cr.chance;}
}criticalParam;

#endif // COMMON_TYPES_H
