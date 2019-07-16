#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QQmlApplicationEngine>

class GameGui
{
public:
    void registerObject(QObject *obj, const QString& qmlName);
    void run();

private:
    QQmlApplicationEngine _engine;
};

#endif //GAMEGUI_H
