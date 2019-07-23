#include "itemweapon.h"

ItemWeapon::ItemWeapon(ItemWeaponAttribute parameters) : Item(parameters.ItemBaseParameters)
{
    _AttributeWeapon = parameters;
}

ItemWeapon::~ItemWeapon()
{

}


