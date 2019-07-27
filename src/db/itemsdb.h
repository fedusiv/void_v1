#ifndef ITEMSDB_H
#define ITEMSDB_H

#include <QHash>
#include <QJsonObject>

#include <items/itemtype.h>

class Item;

class ItemsDataBase
{
public:
    ItemsDataBase();
    Item* getItem(QString id) { return _items[id]; }

private:
    Item* getItemByType(QJsonObject itemObj, ItemType type);

private:
    QHash<QString, Item*> _items;
};

#endif //ITEMSDB_H
