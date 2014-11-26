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

#include "Printheads/PrintheadsController.h"
#include "printerengine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    PrinterEngine* pe = new PrinterEngine(PrinterEngine::LowCapacity);

    PrintheadsController* phController = new PrintheadsController();

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));
    engine.rootContext()->setContextProperty("printer_", pe);
    engine.rootContext()->setContextProperty("userModel_", uc);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
