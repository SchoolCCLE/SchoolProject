#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include <QVariant>
#include "JobList.h"
#include "Job.h"
#include "JobGeneratorFake.h"
#include "JobManager.h"
#include <QtConcurrent/QtConcurrent>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<Job>("JobManagement",1,0,"Job");

    JobManager* manager = new JobManager(engine.rootContext());
    JobGeneratorFake* generator = new JobGeneratorFake(qApp);
    QObject::connect(generator, SIGNAL(jobGenerated(Job*)), manager, SLOT(addJob(Job*)));
    generator->start();
    manager->start();


    engine.rootContext()->setContextProperty("list", QVariant::fromValue(manager->list()));
    engine.load(QUrl(QStringLiteral("qrc:///JobView.qml")));

    return app.exec();
}
