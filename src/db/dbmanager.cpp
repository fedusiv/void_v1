#include "dbmanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include <minmax.h>

#include <lear/class_list.h>

GameFactory::GameFactory()
    : _filesPath("../../data/json/")
{
    initItems();
    initSkills();
}

void GameFactory::initItems()
{
    QJsonDocument itemsDoc_ = getJsonFromFile("items.json");

    if(itemsDoc_.isArray())
    {
        QJsonObject item_;
        ItemAttribute itemAttribute_;
        QJsonArray items_ = itemsDoc_.array();
        for (QJsonValue itemValue_ : items_)
        {
            if(itemValue_.isObject())
            {
                readAttribute(itemValue_.toObject(), itemAttribute_);
                _items.insert(itemAttribute_.Name, new Item(itemAttribute_));
            }
            else
            {
                //TODO: wrong object handling
            }
        }
    }
    else
    {
        //TODO: wrong file format handling
    }
}

void GameFactory::initSkills()
{
    QJsonDocument skillsDoc = getJsonFromFile("skills.json");

    //TODO: parse skills
}

QJsonDocument GameFactory::getJsonFromFile(QString name)
{
    QFile file_(_filesPath + name);
    file_.open(QIODevice::ReadOnly);
    QJsonDocument doc_ = QJsonDocument::fromJson(file_.readAll());
    return doc_;
}

void GameFactory::readAttribute(QJsonObject item, ItemAttribute &outAttribute)
{
    // parsing basic values:

    outAttribute.id = item["id"].toString();
    outAttribute.Name = item["name"].toString();
    outAttribute.Desc = item["desc"].toString();
    // outAttribute.Type must be defined by input file
    outAttribute.Level = item["level"].toInt();
    outAttribute.Weight = item["weight"].toDouble();
    outAttribute.image = item["img"].toString();
    outAttribute.NextLevelItem = item["nextlevel"].toString();

    // parsing arrays:

    QJsonArray reqstats_ = item["reqstats"].toArray();
    for (int stat = 0; stat < min(RequireStatsCount, reqstats_.size()); stat++)
    {
      outAttribute.Requirements[stat] = reqstats_[stat].toInt();
    }

    QJsonArray lears_ = item["lears"].toArray();
    Lear lear_;
    for (QJsonValue jsonLear_ : lears_)
    {
        lear_ = strToLear(jsonLear_.toString());
        if(lear_ < LearCount)
        {
            outAttribute.Lears.append(lear_);
        }
    }
}
