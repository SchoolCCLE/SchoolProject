#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>
#include "logincontroler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    LoginControler* _model = new LoginControler();
    //DataBaseController* _dbmodel = new DataBaseController();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_model",_model);
    //engine.rootContext()->setContextProperty("_dbmodel",_dbmodel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
