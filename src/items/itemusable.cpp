#include "itemusable.h"

ItemUsable::ItemUsable(ItemUsableAttribute property) : Item(property.itemBaseParameters)
{
    _AttributeUsable = property;
}

int ItemUsable::getDuration()
{
    return _AttributeUsable.duration;
}

ItemUsableType ItemUsable::getUsableType()
{
    return  _AttributeUsable.type;
}
