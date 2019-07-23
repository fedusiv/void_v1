#include "itemweapon.h"

ItemWeapon::ItemWeapon(ItemWeaponAttribute parameters) : Item(parameters.ItemBaseParameters)
{
    _AttributeWeapon = parameters;
}

ItemWeapon::~ItemWeapon()
{

}

ItemWeaponDamage ItemWeapon::getDamage()
{
    ItemWeaponDamage damage;
    damage.damage = _AttributeWeapon.Damage;
    damage.Type = _AttributeWeapon.Type;
    return damage;
}


