#include "gamegui.h"

#include <QQmlContext>

/* @desc: register obj under qmlName for using it from qml */
void GameGui::registerObject(QObject *obj, const QString& qmlName)
{
    if(obj)
    {
        _engine.rootContext()->setContextProperty(qmlName, obj);
    }
}

/* @desc: starting qml engine */
void GameGui::run()
{
    _engine.load("qrc:/main.qml");
}
