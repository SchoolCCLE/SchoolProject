#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>
#include <QTime>
#include "usercontroller.h"
#include "showqml.h"
#include "printerengine.h"
#include "Printheads/PrintheadsController.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QTime time;
    time.start();

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    PrintheadsController* phController = new PrintheadsController();

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));

    engine.rootContext()->setContextProperty("userModel_", uc);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    PrinterEngine* pe = new PrinterEngine(0);
    pe->setStateNum(1);
    pe->setStateText("Printing");
    pe->setTiempo(time.elapsed());

    qDebug() << "Tipo de impresora:" << pe->getTipo() << endl
             << "Estado de la impresora" << pe->getStateText() << endl
             << "Tiempo activa:" << pe->getTiempo() << endl;

    engine.rootContext()->setContextProperty("pe_",pe);

    return app.exec();
}
