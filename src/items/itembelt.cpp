#include "itembelt.h"

ItemBelt::ItemBelt(ItemBeltAttribute property) : Item ( property.itemBaseParameters)
{
    _AttributeBelt = property;
}
