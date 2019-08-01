#include "jsonutil.h"

#include <QJsonObject>
#include <QJsonArray>

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
    outAttribute.name = sourceObj["name"].toString();
    outAttribute.desc = sourceObj["desc"].toString();
    // outAttribute.Type must be defined by input file
    outAttribute.level = sourceObj["level"].toInt();
    outAttribute.weight = sourceObj["weight"].toDouble();
    outAttribute.image = sourceObj["img"].toString();
    outAttribute.nextLevelItem = sourceObj["next_level"].toString();

    // parsing arrays:

    QJsonArray reqstats_ = sourceObj["reqstats"].toArray();
    for (int stat = 0; stat < std::min(INT(RequireStatsCount), reqstats_.size()); stat++)
    {
      outAttribute.requirements[stat] = reqstats_[stat].toInt();
    }

    QJsonArray lears_ = sourceObj["lears"].toArray();
    Lear lear_;
    for (QJsonValue jsonLear_ : lears_)
    {
        lear_ = strToLear(jsonLear_.toString());
        if(lear_ < LearCount)
        {
            outAttribute.lears.append(lear_);
        }
    }

    //parsing other_values:
    QJsonObject otherValues_ = sourceObj["other_values"].toObject();
    if(!otherValues_.isEmpty())
    {
        outAttribute.otherValues = otherValues_.toVariantMap();
    }
}
