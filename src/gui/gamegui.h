#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QQmlApplicationEngine>

class GameGui
{
public:
    void registerObject(QObject *obj, const QString& qmlName);
    void run();

private:
    QQmlApplicationEngine engine_;
};

#endif //GAMEGUI_H
