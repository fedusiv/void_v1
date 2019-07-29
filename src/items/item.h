#ifndef ITEM_H
#define ITEM_H


#include <QString>
#include <QList>
#include <QDebug>
#include "return_codes.h"

#include "common_types.h"
#include "lear/class_list.h"
#include "itemtype.h"

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
struct ItemChargeAbility
{
    bool reChargable;
    int charges;
};


/*
 * Main foundation of all Item properties
 */
struct ItemAttribute
{
    QString id;
    QString name;
    QString desc;
    ItemType type;
    QList<Lear> lears;      // store array of classes
    StatsRequire requirements;
    int level;
    float weight;
    // Remove values
    ItemChargeAbility chargability;
    QString image;
    QString nextLevelItem;

    QVariantMap otherValues; //store custom values
};

/*
 * Additional  properties for Weapon
 */
struct ItemWeaponAttribute
{
    WeaponHands hands;
    float damage;
    DamageTypes type;
    QList<float> scaleValue;
    MainStats scaleAttribute;
    ItemAttribute itemBaseParameters;
};

/*
 * Additional  properties for Usable Items
 */
struct ItemUsableAttribute
{
    ItemUsableType type;
    int duration;
    ItemAttribute itemBaseParameters;
};

/*
 * Additional  properties for Cloth
 */
struct ItemClothAttribute
{
    float armor;
    DamageTypes armorType;
    ItemClothType clothType;
    ItemAttribute itemBaseParameters;
};

/*
 * Additional  properties for Usable Items
 */
struct ItemBeltAttribute
{
    int size;
    ItemAttribute itemBaseParameters;
};


/*
 * Describe the armor property of cloth
 */
struct itemClothArmor
{
    float armor;
    DamageTypes type;
};


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
    EquipReturnCode checkRequirments( StatsRequire player_stats);  // return true if player can equip this element



    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual ItemClothType getClothType() { return ItemClothType::ClothCount;} // virtual method for get type of cloth equipment
    virtual ItemWeaponDamage getDamage();                  // virtual method for weapon children, it return damage parametr
    virtual itemClothArmor getArmor();                    // virtual method for cloth children, returns armor of cloth

protected:
    ItemAttribute _Attribute;           // all base parameters of Item
    bool _Equipped;                     // flag shows is Item is Equipped.

};
#endif // ITEM_H
