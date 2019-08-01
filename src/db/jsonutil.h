#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QJsonDocument>
#include <QVariant>

#include <items/item.h>

#include <type_traits>

// two extremly complicated but maybe somehow useful macro
#define READ_JVALUE(target, obj, name) target = qvariant_cast<decltype(target)>(obj[name].toVariant());
#define READ_JARRAY(target, obj, name) \
    QJsonArray arr = obj[name].toArray(); \
    for(size_t i = 0; i < target.size(); i++) \
    {\
        target[i] = qvariant_cast<std::remove_reference<decltype(target[0])>::type>(arr[i].toVariant()); \
    }

QJsonDocument getJsonFromFile(QString path);
void readAttribute(QJsonObject item, ItemAttribute &outAttribute);

#endif //JSONUTIL_H
