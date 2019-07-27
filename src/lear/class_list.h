#ifndef CLASS_LIST_H
#define CLASS_LIST_H

#include <QString>
#include <commonmacros.h>

enum Lear
{
    Assassin,
    Rogue,
    Warrior,
    Mage,
    Knight,
    Grey,
    LearCount
};

static QString LearNames[] =
{
    "Assassin",
    "Rogue",
    "Warrior",
    "Mage",
    "Knight",
    "Grey"
};

/*
 * Lear -> QString
 */
inline  QString learToStr(Lear type)
{
    return LearNames[static_cast<int>(type)];
}

/*
 * QString -> Lear
 */
inline Lear strToLear(QString str)
{
    for (int i = 0; i < SIZE_OF_ARRAY(LearNames); i++)
    {
        if(!str.compare(LearNames[i], Qt::CaseInsensitive))
        {
            return static_cast<Lear>(i);
        }
    }

    return Lear::LearCount; //default lear
}

#endif // CLASS_LIST_H
