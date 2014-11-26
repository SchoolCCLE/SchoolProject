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
#include <printerengine.h>

#include "Printheads/PrintheadsController.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);
    PrinterEngine* pe = new PrinterEngine(1);
    pe->setParent(&app);

    PrintheadsController* phController = new PrintheadsController();

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));
    engine.rootContext()->setContextProperty("cartridges_",QVariant::fromValue(phController->printheads()));//NECESITAMOS CLASE CARTRIDGES QUE DEFINA NUMERO DE CARTRIDGES.
    engine.rootContext()->setContextProperty("_myModel",pe);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));


    return app.exec();
}
