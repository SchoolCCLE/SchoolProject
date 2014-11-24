#include <QApplication>
#include <QQmlApplicationEngine>
#include <logincontroller.h>
#include <QObject>
#include <QQmlContext>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LoginController * loginController = new LoginController();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    for(int i = 0, j = engine.rootObjects().count(); i<j; i++){
        QObject::connect(engine.rootObjects().at(i), SIGNAL(login(QString,QString)), loginController, SLOT(loginAttempt(QString,QString)));
    }

    return app.exec();
}
