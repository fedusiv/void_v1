#ifndef ITEMBELT_H
#define ITEMBELT_H

#include "item.h"

class ItemBelt : Item
{
protected:
    ItemBeltAttribute _AttributeBelt;
public:
    ItemBelt(ItemBeltAttribute property);
    int getBeltSize() { return _AttributeBelt.size;}    // return the size of Belt
};

#endif // ITEMBELT_H
