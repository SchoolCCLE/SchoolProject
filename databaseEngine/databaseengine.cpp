#include "databaseengine.h"
#include <assert.h>
#include <QDebug>
#include <QSqlQuery>

Users *Users::getInstance()
{
    static Users* theInstance = new Users();
    return theInstance;
}

void Users::setDatabase(QSqlDatabase dataBase)
{
    dataBase_ = dataBase;
    sqlQuery_ = new QSqlQuery(dataBase_);
    qDebug () << "Created table users" << createTables();
}

bool Users::setUser(QList<QVariant> data)
{
    bool result = sqlQuery_->exec(QString("INSERT OR REPLACE INTO Users VALUES (%1,'%2','%3','%4')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toString()) \
                           .arg(data.at(2).toString()) \
                           .arg(data.at(3).toString()));
    if(result)
    {
        emit userDataChanged();
    }
    return result;
}

Users::Users(QObject *parent):QObject(parent),sqlQuery_(NULL)
{

}

bool Users::createTables()
{
    assert( dataBase_.isOpen() );
    assert(sqlQuery_);


    bool result = true;

    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'Users'"
                              "('UserId'  INTEGER PRIMARY KEY,"
                              "'UserName' TEXT NOT NULL  UNIQUE,"
                              "'FullName' TEXT,"
                              "'Passwd'   TEXT)");

    QList<QVariant> data;
    data << QVariant(1) << QVariant("rootben") << QVariant("Super User") << QVariant("PASS");

    result |= setUser(data);



    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'AccessLevel'"
                              "('LevelId' INTEGER PRIMARY KEY,"
                              "'LevelName' TEX T NOT NULL UNIQUE)");
    result |= sqlQuery_->exec(QString("INSERT OR REPLACE INTO AccessLevel VALUES (1,'Admin')"));
    result |= sqlQuery_->exec(QString("INSERT OR REPLACE INTO AccessLevel VALUES (2,'User')"));


    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'UserAccess'"
                              "('UserId' INTEGER ,"
                              "'LevelId' INTEGER ,"
                              "PRIMARY KEY ('UserId', 'LevelId'))");
    result |= sqlQuery_->exec(QString("INSERT OR REPLACE INTO UserAccess VALUES (1,1)"));

    return result;
}

DatabaseEngine *DatabaseEngine::getInstance()
{
    static DatabaseEngine* theInsance = new DatabaseEngine();

    return theInsance;
}

DatabaseEngine::~DatabaseEngine()
{
    dataBase_.close();
}

bool DatabaseEngine::closeDB()
{
    dataBase_.close();
    return !dataBase_.isOpen();

}

DatabaseEngine::DatabaseEngine(QObject *parent) :
    QObject(parent)
{
    static bool initialized = false;
    if(!initialized){
        initialized = true;
        openDB();
    }
    users_ = Users::getInstance();
    users_->setParent(this);
    users_->setDatabase(dataBase_);

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
    databaseName_ = path;
    qDebug() << "Path " << databaseName_;
    dataBase_.setDatabaseName(path);
    return dataBase_.open();
}

bool DatabaseEngine::deleteDB()
{
    dataBase_.close();
    return QFile::remove(databaseName_);
}

QSqlError DatabaseEngine::lastError()
{
    return dataBase_.lastError();
}



