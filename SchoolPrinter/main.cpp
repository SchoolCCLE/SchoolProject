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
#include <Cartridges/cartridgescontroller.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    PrintheadsController* phController = new PrintheadsController();

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));

    engine.rootContext()->setContextProperty("userModel_", uc);

    PrinterEngine *printerOne = new PrinterEngine(PrinterEngine::HIGH_CAPACITY);
    engine.rootContext()->setContextProperty("printerOne_", printerOne);

    CartridgesController* caController = new CartridgesController(printerOne->getPrinterType());

    engine.rootContext()->setContextProperty("cartridgesNumber", printerOne->getPrinterType());
    engine.rootContext()->setContextProperty("cartridges", QVariant::fromValue(caController->cartridges()));

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
