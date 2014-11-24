#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>
#include <controler.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlEngine *engine_= new QQmlEngine();
    QQuickView *view = new QQuickView(engine_,NULL);

    Controler *controler = Controler::getInstance();

    view->rootContext()->setContextProperty("obj_",controler);

    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    QObject::connect(view->rootObject(), SIGNAL(buttonLogIn(QString, QString) ),
                             controler, SLOT(recibeUserIdentification(QString,QString)) );


    controler->dababaseEngine_->closeDB();

    return app.exec();
}
