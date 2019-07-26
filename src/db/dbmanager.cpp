#include "dbmanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

GameFactory::GameFactory()
    : _filesPath("../../data/json/")
{
    initItems();
    initSkills();
}

void GameFactory::initItems()
{
    QJsonDocument itemsDoc = getJsonFromFile("items.json");

    if(itemsDoc.isArray())
    {
        QJsonObject item;
        ItemAttribute itemAttribute;
        QJsonArray items = itemsDoc.array();
        for (QJsonValue itemValue : items)
        {
            if(itemValue.isObject())
            {
                item = itemValue.toObject();
                itemAttribute.Name = item["name"].toString();
                itemAttribute.Desc = item["desc"].toString();
                itemAttribute.Type = ItemType::Weapon; //TODO: redo with Q_ENUM and keyToValue()
                itemAttribute.Level = item["level"].toInt();
                itemAttribute.Weight = item["weight"].toDouble();
                itemAttribute.image = item["img"].toString();
                itemAttribute.NextLevelItem = item["nextlevel"].toInt(); //QUESTION: why is it int again?..

                // NOTE:
                // if we make Requirements as int array this thing will look MUCH cleaner
                // with one short loop
                QJsonArray reqstats = item["reqstats"].toArray();
                itemAttribute.Requirements.Strength = reqstats[0].toInt();
                itemAttribute.Requirements.Agility = reqstats[1].toInt();
                itemAttribute.Requirements.Intelligence = reqstats[2].toInt();
                itemAttribute.Requirements.Level = reqstats[3].toInt();

                _items.insert(itemAttribute.Name, new Item(itemAttribute));
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
    QFile file(_filesPath + name);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    return doc;
}
