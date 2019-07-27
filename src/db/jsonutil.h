#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QJsonDocument>

#include <items/item.h>

QJsonDocument getJsonFromFile(QString path);
void readAttribute(QJsonObject item, ItemAttribute &outAttribute);

#endif //JSONUTIL_H
