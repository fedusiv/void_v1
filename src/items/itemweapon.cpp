#include "itemweapon.h"

ItemWeapon::ItemWeapon(ItemWeaponAttribute parameters) : Item(parameters.itemBaseParameters)
{
    _AttributeWeapon = parameters;
}

ItemWeapon::~ItemWeapon()
{

}

ItemWeaponDamage ItemWeapon::getDamage()
{
    ItemWeaponDamage damage;
    damage.damage = _AttributeWeapon.damage;
    damage.Type = _AttributeWeapon.type;
    damage.ScaleValue = _AttributeWeapon.scaleValue;
    damage.ScaleAttribute = _AttributeWeapon.scaleAttribute;
    return damage;
}


