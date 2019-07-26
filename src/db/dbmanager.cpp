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
                item_ = itemValue_.toObject();
                itemAttribute_.Name = item_["name"].toString();
                itemAttribute_.Desc = item_["desc"].toString();
                itemAttribute_.Type = ItemType::Weapon; //TODO: redo with Q_ENUM and keyToValue()
                itemAttribute_.Level = item_["level"].toInt();
                itemAttribute_.Weight = item_["weight"].toDouble();
                itemAttribute_.image = item_["img"].toString();
                itemAttribute_.NextLevelItem = item_["nextlevel"].toInt(); //QUESTION: why is it int again?..

                // NOTE:
                // if we make Requirements as int array this thing will look MUCH cleaner
                // with one short loop
                QJsonArray reqstats_ = item_["reqstats"].toArray();
                itemAttribute_.Requirements.Strength = reqstats_[0].toInt();
                itemAttribute_.Requirements.Agility = reqstats_[1].toInt();
                itemAttribute_.Requirements.Intelligence = reqstats_[2].toInt();
                itemAttribute_.Requirements.Level = reqstats_[3].toInt();

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
