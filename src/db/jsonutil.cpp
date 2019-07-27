#include "jsonutil.h"

#include <QJsonObject>
#include <QJsonArray>

#include <minmax.h>

QJsonDocument getJsonFromFile(QString path)
{
    QJsonDocument doc_;
    QFile file_(path);
    if(file_.open(QIODevice::ReadOnly))
    {
        doc_ = QJsonDocument::fromJson(file_.readAll());
    }

    return doc_;
}

void readAttribute(QJsonObject sourceObj, ItemAttribute &outAttribute)
{
    // parsing basic values:

    outAttribute.id = sourceObj["id"].toString();
    outAttribute.Name = sourceObj["name"].toString();
    outAttribute.Desc = sourceObj["desc"].toString();
    // outAttribute.Type must be defined by input file
    outAttribute.Level = sourceObj["level"].toInt();
    outAttribute.Weight = sourceObj["weight"].toDouble();
    outAttribute.image = sourceObj["img"].toString();
    outAttribute.NextLevelItem = sourceObj["nextlevel"].toString();

    // parsing arrays:

    QJsonArray reqstats_ = sourceObj["reqstats"].toArray();
    for (int stat = 0; stat < min(RequireStatsCount, reqstats_.size()); stat++)
    {
      outAttribute.Requirements[stat] = reqstats_[stat].toInt();
    }

    QJsonArray lears_ = sourceObj["lears"].toArray();
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
