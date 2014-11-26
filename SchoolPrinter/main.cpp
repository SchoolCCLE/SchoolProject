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
#include "QObject"

#include "Printheads/PrintheadsController.h"
#include "printerengine.h"
#include "cartuchocontroller.h"
#include "cartuchomodel.h"

void initializeCartucho(QList<QObject*> list, PrinterEngine* printer){
    if (printer->type() == "High Capacity") {
        //Create 2 cartdriges for each color
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                QString color;
                switch (i){
                case 0: color = "CYAN";
                    break;
                case 1: color = "MAGENTA";
                    break;
                case 2: color = "YELLOW";
                    break;
                case 3: color = "BLACK";
                    break;
                }

                CartuchoModel* cartucho = new CartuchoModel(color);
                QObject::connect(cartucho, SIGNAL(statusChanged(QString)), printer, SLOT(setStatus(QString)));
                list.append(cartucho);
            }
        }
    }else {
        for(int i = 0; i < 4; i++) {
            QString color;
            switch (i){
            case 0: color = "CYAN";
                break;
            case 1: color = "MAGENTA";
                break;
            case 2: color = "YELLOW";
                break;
            case 3: color = "BLACK";
                break;
            }

            CartuchoModel* cartucho = new CartuchoModel(color);
            QObject::connect(cartucho, SIGNAL(statusChanged(QString)), printer, SLOT(setStatus(QString)));
            list.append(cartucho);
        }
    }

}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    PrinterEngine* pe = new PrinterEngine(PrinterEngine::LowCapacity);

    PrintheadsController* phController = new PrintheadsController();
    CartuchoController* cartController = new CartuchoController();

    QList<QObject*> listaCartuchos;
    initializeCartucho(listaCartuchos, pe);
    cartController->setCartuchos(listaCartuchos);

    engine.rootContext()->setContextProperty("printheads", QVariant::fromValue(phController->printheads()));
    engine.rootContext()->setContextProperty("printer_", pe);
    engine.rootContext()->setContextProperty("cartuchos_", QVariant::fromValue(cartController->cartuchos()));
    engine.rootContext()->setContextProperty("userModel_", uc);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
