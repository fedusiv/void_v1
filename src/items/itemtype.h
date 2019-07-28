#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QString>

#include <commonmacros.h>

/*
 * Types of all equipments
 */
enum class ItemType{
    Weapon,
    Belt,
    Cloth,
    Usable,
    ItemTypesCount //useless item, default type - for debugging purpose
};

/*
 * QString names of all types
 */
static const QString itemTypeNames[] =
{
    "weapon",
    "belt",
    "cloth",
    "usable"
};

/*
 * get number of item types
 */
constexpr unsigned int getItemTypesCount() { return INT(ItemType::ItemTypesCount); }

/*
 * ItemType -> int
 */
inline int itemTypeToInt(ItemType type)
{
    return INT(type);
}

/*
 * int -> ItemType
 */
inline ItemType intToItemType(int type)
{
    return static_cast<ItemType>(type);
}

/*
 * int -> QString
 */
inline  QString itemTypeToStr(int type)
{
    return itemTypeNames[type];
}

/*
 * ItemType -> QString
 */
inline  QString itemTypeToStr(ItemType type)
{
    return itemTypeToStr(static_cast<int>(type));
}

/*
 * QString -> ItemType
 */
inline ItemType strToItemType(QString str)
{
    for (int i = 0; i < SIZE_OF_ARRAY(itemTypeNames); i++)
    {
        if(!str.compare(itemTypeNames[i], Qt::CaseInsensitive))
        {
            return static_cast<ItemType>(i);
        }
    }

    return ItemType::ItemTypesCount;
}

#endif //ITEMTYPE_H
