#include "itemsdb.h"

#include <items/item.h>
#include <db/jsonutil.h>
#include <commonmacros.h>

#include <QJsonObject>
#include <QJsonArray>

#include <items/item.h>

ItemsDataBase::ItemsDataBase()
{
    for (int type = 0; type < INT(ItemType::ItemTypesCount); type++) //loop for all item types
    {
        for(int lvl = 0; lvl <= MAX_ITEM_LEVEL; lvl++) //loop for all item levels
        {
            QString itemFile(JSON_PATH + JSON_ITEMS_DIR
                             + itemTypeToStr(type) + QString::number(lvl) + ".json");
            QJsonDocument doc_ = getJsonFromFile(itemFile);

            if(!doc_.isEmpty() && doc_.isArray())
            {
                QJsonArray items_ = doc_.array();
                for (QJsonValue itemValue_ : items_) //loop for all items in file
                {
                    if(itemValue_.isObject())
                    {
                        QJsonObject itemObj_ = itemValue_.toObject();
                        ItemAttribute itemAttribute_;
                        readAttribute(itemObj_, itemAttribute_);

                        Item* item_ = getItemByType(itemObj_, intToItemType(type));
                        _items[type].insert(itemAttribute_.id, item_);
                    }
                }
            }
        }
    }
}

Item* ItemsDataBase::getItem(QString id) const
{
    Item* item = nullptr;
    for (const ItemsHash& hash : _items)
    {
        if(hash.contains(id))
        {
            item = hash[id];
            break;
        }
    }

    return item;
}

Item* ItemsDataBase::getItemByType(QJsonObject itemObj, ItemType type)
{
    //TODO: create sertain Item & read specific params according to type
    return nullptr;
}
