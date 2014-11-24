#include <QApplication>
#include <QQmlApplicationEngine>
#include "databaseEngine/databaseengine.h"
#include <QQmlEngine>
#include <QQmlContext>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Users*_model = _model->getInstance();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_model",_model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
