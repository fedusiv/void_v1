#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <skills/skill.h>
#include <items/item.h>

#include <QJsonObject>
#include <QHash>


class GameFactory
{
public:
    GameFactory();

    Item* getItem(QString name);
    Skill* getSkill(QString name);

private:
    QJsonDocument getJsonFromFile(QString name);
    void initItems();
    void initSkills();

private:
    const QString _filesPath;
    QHash<QString, Item*> _items;
    QHash<QString, Skill*> _skills;
};

#endif //DBMANAGER_H
