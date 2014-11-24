#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QDebug>
#include "usercontroller.h"
#include "showqml.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UserController* uc = UserController::getInstance();
    uc->setParent(&app);

    ShowQml * qmlView = new ShowQml();

    qmlView->getContext()->setContextProperty("userModel_",uc);

    QObject::connect(qmlView->getEngine(),SIGNAL(quit()),&app,SLOT(quit()));
    qmlView->setQml("login.qml");

    QObject::connect(qmlView->getRootItem() ,SIGNAL(dataInput(QString,QString)),uc,SLOT(checkLoging(QString,QString)));
    QObject::connect(qmlView->getRootItem() ,SIGNAL(cancel()),&app,SLOT(quit()));
    QObject::connect(uc ,SIGNAL(accessGranted(bool)),qmlView,SLOT(accessGranted(bool)));


    qmlView->show();


    return app.exec();
}