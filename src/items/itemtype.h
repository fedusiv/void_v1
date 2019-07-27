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
    Trash //useless item, default type - for debugging purpose
};

/*
 * QString names of all types
 */
static const QString itemTypeNames[] =
{
    "Weapon",
    "Belt",
    "Cloth",
    "Usable",
    "Trash"
};

/*
 * ItemType -> QString
 */
inline  QString itemTypeToStr(ItemType type)
{
    return itemTypeNames[static_cast<int>(type)];
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

    return ItemType::Trash;
}

#endif //ITEMTYPE_H
