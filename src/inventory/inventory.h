#ifndef INVENTORY_H
#define INVENTORY_H

#include "items/itemweapon.h"
#include "return_codes.h"


class Equipped
{
public:
    Equipped(){ hand = WeaponHands::None;}
    // using qlist needs cause player could wear a few in a time
    Item *  weaponMain;
    Item *  weaponSecond;
    WeaponHands hand;
    Item *  head;
    Item *  body;
    Item *  arms;
    Item *  legs;
    Item *  feet;
    Item *  belt;
    QList<Item *>  accesorize;

};


/*
 * Class operates with Player Inventory.
 */
class Inventory
{
private:
    float _WeightMax;
    float _WeightCurrent;

    QList<Item *> _InventoryList;
    Equipped _Equipped;
public:
    Inventory(float weightMax = 0);
    AddToInventoryStatus addItemToInventory(Item * item);

    EquipReturnCode equipMainWeapon(ItemWeapon * weapon);
    EquipReturnCode equipSecondWeapon(ItemWeapon * weapon);

};

#endif // INVENTORY_H
