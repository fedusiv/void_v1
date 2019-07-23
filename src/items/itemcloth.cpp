#include "itemcloth.h"

ItemCloth::ItemCloth(ItemClothAttribute attribute) : Item (attribute.ItemBaseParameters)
{
    _AttributeCloth = attribute;
}

ItemClothType ItemCloth::getClothType()
{
    return _AttributeCloth.ClothType;
}

ItemClothArmor ItemCloth::getArmor()
{
    ItemClothArmor armor;
    armor.armor = _AttributeCloth.Armor;
    armor.Type = _AttributeCloth.ArmorType;
    return armor;
}
