#ifndef ITEMWEAPON_H
#define ITEMWEAPON_H

#include "item.h"
#include <QList>


class ItemWeapon : public Item
{

protected:
 ItemWeaponAttribute _AttributeWeapon;

public:
    ItemWeapon(ItemWeaponAttribute parameters);
    ~ItemWeapon() override;

    int getHands() override { return _AttributeWeapon.Hands;}
    ItemWeaponDamage getDamage() override;

};

#endif // ITEMWEAPON_H
