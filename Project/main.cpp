#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>
//#include <controler.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlEngine *engine_= new QQmlEngine();
    QQuickView *view = new QQuickView(engine_,NULL);

    //Controler *obj = new Controler();
//    view->rootContext()->setContextProperty("obj_",obj);

    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    /*
     *  Aquí van los connect
     */


    return app.exec();
}
