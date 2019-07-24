#include "dbmanager.h"

#include <QFile>

GameDataManager::GameDataManager()
    : _filesPath("../../data/json/")
{
    initItems();
    initSkills();
}

void GameDataManager::initItems()
{
    QJsonObject itemsObj = getJsonFromFile("items.json");

    //parse items
}

void GameDataManager::initSkills()
{
    QJsonObject itemsObj = getJsonFromFile("skills.json");

    //parse skills
}

QJsonObject GameDataManager::getJsonFromFile(QString name)
{
    QFile file(_filesPath + name);
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    return doc.object();
}
