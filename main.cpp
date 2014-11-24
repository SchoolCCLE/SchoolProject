#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "databaseEngine/databaseengine.h"
#include "usercontroller.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DatabaseEngine*_model = DatabaseEngine::getInstance();
    QList<QVariant> user;
    UserController userControl;

    user.push_back(QVariant(1));
    user.push_back(QVariant("admin"));
    user.push_back(QVariant("Administrador por defecto"));
    user.push_back(QVariant("1234"));
    _model->setUser(user);
    user.clear();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_controller",_controller);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
