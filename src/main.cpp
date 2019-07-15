#include <QGuiApplication>

#include <gamemanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    GameManager game;

    return app.exec();
}
