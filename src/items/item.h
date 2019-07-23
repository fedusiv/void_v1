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
    NotCloth
};

typedef struct ItemChargeAbility
{
    bool ReChargable;
    int Charges;
}ItemChargeAbility;

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

typedef struct ItemWeaponAttribute
{
    int Hands;
    float Damage;
    DamageTypes Type;
    QList<float> ScaleValue;
    QList<MainStats> ScaleAttribute;
    ItemAttribute ItemBaseParameters;
}ItemWeaponAttribute;

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
    ItemType getEquipType();
    EquipReturnCode checkRequirments( int player_level, int ** type_points);  // return true if player can equip this element



    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual ItemClothType getClothType() { return ItemClothType::NotCloth;} // virtual method for get type of cloth equipment
    virtual float getDamage(){return 0.0;}                    // virtual method for weapon children, it return damage parametr
    virtual float getArmor(){return 0.0;}                    // virtual method for cloth children, returns armor of cloth

protected:
    ItemAttribute _Attribute;           // all base parameters of Item
    bool _Equipped;                     // flag shows is Item is Equipped.

};
#endif // ITEM_H
