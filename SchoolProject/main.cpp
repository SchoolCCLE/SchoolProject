#include <QApplication>
#include <QQmlApplicationEngine>
#include "databaseengine.h"
#include <QDebug>
#include <QQmlContext>
#include <QQuickItem>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    DatabaseEngine  *database;
    database = database->getInstance();
    if(database->getUsers().isEmpty())
    {
        engine.load(QUrl(QStringLiteral("qrc:/startup.qml")));
    }
    engine.rootContext()->setContextProperty("model_",database);
    QObject::connect(engine.rootObjects().at(0), SIGNAL(signalsetuser(QString, QString, QString)),
                         &app, SLOT(slotSetUsers(QString,QString,QString)));

    return app.exec();
}
