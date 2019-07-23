#ifndef ITEM_H
#define ITEM_H


#include <QString>
#include <QList>
#include <QDebug>
#include "return_codes.h"

#include "common_types.h"

/*
 * Types of all equipments
 */
enum class ItemType{
    Weapon,
    Belt,
    Cloth,
    Usable
};

/*
 * Types of only cloth equipment
 */
enum  ItemClothType{
    Head,
    Body,
    Arms,
    Legs,
    Feet,
    Accessorize,
    ClothCount
};

/*
 * Types of all usable items
 */
enum ItemUsableType
{
    Heal,
    Damage,
    Armor
};

/*
 *  structure keep information about charge ability of Item
 */
typedef struct ItemChargeAbility
{
    bool ReChargable;
    int Charges;
}ItemChargeAbility;


/*
 * Main foundation of all Item properties
 */
typedef struct ItemAttribute
{
    QString Name;
    QString Desc;
    ItemType Type;
    //Lear,
    MainStatsRequire Requirements;
    int Level;
    float Weight;
    uint32_t values;
    ItemChargeAbility Chargability;
    QString image;
    int NextLevelItem;
}ItemAttribute;

/*
 * Additional  properties for Weapon
 */
typedef struct ItemWeaponAttribute
{
    int Hands;
    float Damage;
    DamageTypes Type;
    QList<float> ScaleValue;
    QList<MainStats> ScaleAttribute;
    ItemAttribute ItemBaseParameters;
}ItemWeaponAttribute;

/*
 * Additional  properties for Usable Items
 */
typedef struct ItemUsableAttribute
{
    ItemUsableType Type;
    int duration;
    ItemAttribute ItemBaseParameters;
}ItemUsableAttribute;

/*
 * Additional  properties for Cloth
 */
typedef struct ItemClothAttribute
{
    float Armor;
    DamageTypes ArmorType;
    ItemClothType ClothType;
    ItemAttribute ItemBaseParameters;
}ItemClothAttribute;

/*
 * Additional  properties for Usable Items
 */
typedef struct ItemBeltAttribute
{
    int size;
    ItemAttribute ItemBaseParameters;
}ItemBeltAttribute;

/*
 * Describe the damage property of weapon
 */
typedef struct ItemWeaponDamage
{
    float damage;
    DamageTypes Type;
}ItemWeaponDamage;

/*
 * Describe the armor property of cloth
 */
typedef struct ItemClothArmor
{
    float armor;
    DamageTypes Type;
}ItemClothArmor;


class Item
{
public:
    Item(ItemAttribute attribute);
    virtual ~Item(){}

    int getLevel(); // returns equipment level
    float getWeight();  // returns equipment size
    QString getName();// returns name of equipment
    void setName(QString name);
    QString getDesc();    // return string about desc
    bool isEquipped();    // return flag of equipped status
    void setEquipped(bool status);  // set equipped or useless equip
    ItemType getItemType();
    EquipReturnCode checkRequirments( MainStatsRequire player_stats);  // return true if player can equip this element



    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual ItemClothType getClothType() { return ItemClothType::ClothCount;} // virtual method for get type of cloth equipment
    virtual ItemWeaponDamage getDamage();                  // virtual method for weapon children, it return damage parametr
    virtual ItemClothArmor getArmor();                    // virtual method for cloth children, returns armor of cloth

protected:
    ItemAttribute _Attribute;           // all base parameters of Item
    bool _Equipped;                     // flag shows is Item is Equipped.

};
#endif // ITEM_H
