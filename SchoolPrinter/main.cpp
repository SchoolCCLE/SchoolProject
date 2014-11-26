#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>
#include <QTime>
#include <QtQml>
#include "usercontroller.h"
#include "showqml.h"
#include "printerengine.h"
#include "Printheads/PrintheadsController.h"
#include "Printheads/Cartridgecontroller.h"
#include "cartridgemodel.h"


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

    PrinterEngine* pe = new PrinterEngine(0);

    pe->setStateNum(2);
    pe->setStateText("Warning");
    pe->setTiempo( time.elapsed() );

    qDebug() << "Tipo de impresora:" << pe->getTipo() << endl
             << "Estado de la impresora" << pe->getStateText() << endl
             << "Tiempo activa:" << pe->getTiempo() << endl;

    CartridgeController* cc = new CartridgeController();
    //CartridgeModel::declareQML();

    engine.rootContext()->setContextProperty("cartridges", QVariant::fromValue(cc->cartridges()));

    engine.rootContext()->setContextProperty("pe_",pe);

    engine.rootContext()->setContextProperty("userModel_", uc);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
