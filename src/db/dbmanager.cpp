#include "dbmanager.h"

#include <QFile>
#include <QJsonDocument>

GameFactory::GameFactory()
    : _filesPath("../../data/json/")
{
    initItems();
    initSkills();
}

void GameFactory::initItems()
{
    QJsonDocument itemsDoc = getJsonFromFile("items.json");

    //parse items
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
