#ifndef ITEMWEAPON_H
#define ITEMWEAPON_H

#include "item.h"
#include <QList>

#include <commonmacros.h>

class ItemWeapon : public Item
{

protected:
 ItemWeaponAttribute _AttributeWeapon;

public:
    ItemWeapon(ItemWeaponAttribute parameters);
    ~ItemWeapon() override;

    int getHands() override { return _AttributeWeapon.handSize; }
    ItemWeaponDamage getDamage() override;              // Please be sure that you need to set Hand in the inventory

};

#endif // ITEMWEAPON_H
