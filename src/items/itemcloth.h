#ifndef ITEMCLOTH_H
#define ITEMCLOTH_H

#include "item.h"

class ItemCloth : public Item
{
protected:
    ItemClothAttribute _AttributeCloth;
public:
    ItemCloth(ItemClothAttribute attribute);
    ItemClothType getClothType() override;
    ItemClothArmor getArmor() override;
};

#endif // ITEMCLOTH_H
