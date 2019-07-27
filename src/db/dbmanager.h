#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <db/itemsdb.h>

class GameFactory
{
public:
    static void init() { _instance = new GameFactory(); }
    static inline Item* getItem(QString name)
    {
        return _instance ? _instance->getItem(name) : nullptr;
    }

private:
    GameFactory();

private:
    static GameFactory* _instance;

    ItemsDataBase _itemdb;
};

#endif //DBMANAGER_H
