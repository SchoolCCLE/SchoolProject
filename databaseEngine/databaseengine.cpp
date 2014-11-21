#include "databaseengine.h"
#include <assert.h>
#include <QDebug>


Users *Users::getInstance()
{
    static Users* theInstance = new Users();
    return theInstance;
}

Users::Users(QObject *parent):QObject(parent)
{

}

DatabaseEngine *DatabaseEngine::getInstance()
{
    static DatabaseEngine* theInsance = new DatabaseEngine();
    static bool initialized = false;
    if(!initialized){
        initialized = true;
        assert(theInsance->openDB());
    }

    return theInsance;
}

DatabaseEngine::DatabaseEngine(QObject *parent) :
    QObject(parent)
{
    users_ = Users::getInstance();
    users_->setParent(this);
}

bool DatabaseEngine::openDB()
{
    dataBase_ = QSqlDatabase::addDatabase("QSQLITE");
    QString path(QDir::current().path());
    path.append(QDir::separator()).append("db");
    path = QDir::toNativeSeparators(path);
    QDir dir(path);
    dir.mkdir(path);
    path.append(QDir::separator()).append("school.db.sqlite");

    qDebug() << "Path " << path;
    dataBase_.setDatabaseName(path);
    return dataBase_.open();
}

bool DatabaseEngine::deleteDB()
{
    return true;
}

QSqlError DatabaseEngine::lastError()
{
    return QSqlError();
}



