#include "itemsdb.h"

#include <items/item.h>
#include <db/jsonutil.h>
#include <commonmacros.h>

#include <QJsonObject>
#include <QJsonArray>

#include <items/item.h>
#include <items/itemweapon.h>

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
                        Item* item_ = getItemByType(itemObj_, intToItemType(type));
                        if(item_) _items[type].insert(item_->getName(), item_);
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
    switch (type)
    {
        case ItemType::Weapon :
        {
            return getWeaponFromJson(itemObj);
        }
        break;

        //TODO: replicate for all other types

        default:
            return nullptr;
    }
}

Item* ItemsDataBase::getWeaponFromJson(QJsonObject sourceObj)
{
    ItemWeaponAttribute weaponAtt_;
    weaponAtt_.hands = WeaponHands::Both; // = strToHands(sourceObj["hands"].toString());
    weaponAtt_.damage = sourceObj["damage"].isDouble();
    weaponAtt_.type = DamageTypes::Blood; // = strToDmgType(sourceObj["damage_type"].toString());
    for (int stat = 0; stat < 3; stat++)
    {
        //TODO: check wich type scaleAttribute must be
    }

    readAttribute(sourceObj, weaponAtt_.itemBaseParameters);

    return new ItemWeapon(weaponAtt_);
}
