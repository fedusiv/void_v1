#ifndef ITEMSDB_H
#define ITEMSDB_H

#include <QHash>
#include <QJsonObject>

#include <items/itemtype.h>

class Item;

typedef QHash<QString, Item*> ItemsHash;

class ItemsDataBase
{
public:
    ItemsDataBase();
    Item* getItem(QString id) const;

private:
    Item* getItemByType(QJsonObject itemObj, ItemType type);

    Item* getWeaponFromJson(QJsonObject sourceObj);

private:
    ItemsHash _items [getItemTypesCount()]; //array of hashs, each one for certain item type
};

#endif //ITEMSDB_H
