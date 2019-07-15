#include "gamegui.h"

#include <QQmlContext>

//register obj under qmlName for using it from qml
void GameGui::registerObject(QObject *obj, const QString& qmlName)
{
    if(obj)
    {
        engine_.rootContext()->setContextProperty(qmlName, obj);
    }
}

//starting qml engine
void GameGui::run()
{
    engine_.load("qrc:/main.qml");
}
