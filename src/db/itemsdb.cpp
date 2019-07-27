#include "itemsdb.h"

#include <items/item.h>
#include <db/jsonutil.h>
#include <commonmacros.h>

#include <QJsonObject>
#include <QJsonArray>

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
                for (QJsonValue item_ : items_) //loop for all items in file
                {
                    if(item_.isObject())
                    {
                        ItemAttribute itemAttribute_;
                        readAttribute(item_.toObject(), itemAttribute_);


                    }
                }
            }
        }
    }
}
