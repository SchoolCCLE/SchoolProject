#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "logincontroler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    LoginControler* _model = new LoginControler();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_model",_model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
