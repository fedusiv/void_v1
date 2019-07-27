#ifndef ITEMSDB_H
#define ITEMSDB_H

#include <QHash>

class Item;

class ItemsDataBase
{
public:
    ItemsDataBase();
    Item* getItem(QString id) { return _items[id]; }

private:
    inline void readItemWithType() { }

private:
    QHash<QString, Item*> _items;
};

#endif //ITEMSDB_H
