#include "itembelt.h"

ItemBelt::ItemBelt(ItemBeltAttribute property) : Item ( property.ItemBaseParameters)
{
    _AttributeBelt = property;
}
