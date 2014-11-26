#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>
#include "usercontroller.h"
#include "showqml.h"
#include "printerengine.h"
#include "Printheads/PrintheadsController.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    PrintheadsController* phController = new PrintheadsController();

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));

    engine.rootContext()->setContextProperty("userModel_", uc);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    PrinterEngine *p = new PrinterEngine(PrinterEngine::HIGH_CAPACITY);
    p->getPrinterCapacity();
    p->setStatus(0);
    engine.rootContext()->setContextProperty("_model", p);

    return app.exec();
}
