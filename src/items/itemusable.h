#ifndef ITEMUSABLE_H
#define ITEMUSABLE_H

#include "item.h"

class ItemUsable : public Item
{
protected:
    ItemUsableAttribute _AttributeUsable;
public:
    ItemUsable(ItemUsableAttribute property);
    int getDuration();  // get duration in turns of Usable Item
    ItemUsableType getUsableType(); // get Usable Type
    // void Use ( Player, Monster );
};

#endif // ITEMUSABLE_H
