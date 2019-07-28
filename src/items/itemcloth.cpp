#include "itemcloth.h"

ItemCloth::ItemCloth(ItemClothAttribute attribute) : Item (attribute.itemBaseParameters)
{
    _AttributeCloth = attribute;
}

ItemClothType ItemCloth::getClothType()
{
    return _AttributeCloth.clothType;
}

itemClothArmor ItemCloth::getArmor()
{
    itemClothArmor armor;
    armor.armor = _AttributeCloth.armor;
    armor.type = _AttributeCloth.armorType;
    return armor;
}
