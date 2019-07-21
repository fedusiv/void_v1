#ifndef ITEM_H
#define ITEM_H


#include <QString>
#include <QDebug>
#include "return_codes.h"


#define AMOUNT_OF_MAIN_STATS 3
/*
 * Types of all equipments
 */
enum class ItemType{
    Weapon,
    Components,
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
    Belt,
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
    //Lear,
    //Requirments,
    int Level;
    float Weight;
    uint32_t values;
    ItemChargeAbility Chargability;

}ItemAttribute;

class Item
{
public:
    Item(ItemAttribute attribute);
    virtual ~Item(){ qDebug() << "Equip deleted " + _Name; }

    int getLevel(); // returns equipment level
    float getWeight();  // returns equipment size
    QString getName();// returns name of equipment
    void setName(QString name);
    QString getInfo();    // return string info about equip
    QString getDesc();    // return string about desc
    bool isEquipped();    // return flag of equipped status
    void setEquipped(bool status);  // set equipped or useless equip
    ItemType getEquipType();
    EquipReturnCode checkRequirments( int player_level, int ** type_points);  // return true if player can equip this element
    int * getRequirments();     // return pointer to array with requirments values for main stats


    // virtual methods for children class
    virtual int getHands() { return 0;} // virtual method for weapon returns count of required hands
    virtual ItemClothType getClothType() { return ItemClothType::NotCloth;} // virtual method for get type of cloth equipment
    virtual QString getStringType() { return "Equip";}                          // virtual method for printing that is it equipment
    virtual float getDamage(){return 0.0;}                    // virtual method for weapon children, it return damage parametr
    virtual float getArmor(){return 0.0;}                    // virtual method for cloth children, returns armor of cloth

protected:
    int _Level;     // level of equipment
    QString _Name;  // name of equipment
    float _Weight;      // size in inventory of current inventory
    QString _Desc;  // lore description of equip
    bool _Equipped;  // flag shows is equipment equipped
    int _RequiredPoints[3]; // array that represent requirmet points of 3 types ( str, agil, intelligence)

    ItemType  _Type;// type of equipment

};
#endif // ITEM_H
