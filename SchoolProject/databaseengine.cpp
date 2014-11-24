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

datamap Users::getUsers()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM Users");
    while (sqlQuery_->next())
    {
        value.clear();
        value << QVariant(sqlQuery_->value(1).toString()) <<
                 QVariant(sqlQuery_->value(2).toString()) <<
                 QVariant(sqlQuery_->value(3).toString());
        data.insert(sqlQuery_->value(0).toInt(),value);

        qDebug() << "User " << sqlQuery_->value(0).toInt() <<
                    "Name " << QVariant(sqlQuery_->value(1).toString()) <<
                    "Full Name" << QVariant(sqlQuery_->value(2).toString()) <<
                    "Passwd" << QVariant(sqlQuery_->value(3).toString());
    }
    return data;
}

bool Users::setUser(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO Users VALUES (%1,'%2','%3','%4')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toString()) \
                           .arg(data.at(2).toString()) \
                           .arg(data.at(3).toString()));
}

bool Users::deleteUser(QList<QVariant> data)
{
    QString d = QString("DELETE FROM Users WHERE UserId = %1").arg(data.at(0).toInt());
    return sqlQuery_->exec(d);
}

datamap Users::getAceesLevels()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM AccessLevel");
    while (sqlQuery_->next())
    {
        value.clear();
        value << QVariant(sqlQuery_->value(1).toString());
        data.insert(sqlQuery_->value(0).toInt(),value);

        qDebug() << "Level Id" << sqlQuery_->value(0).toInt() <<
                    "Name " << QVariant(sqlQuery_->value(1).toString());
    }
    return data;
}

bool Users::setAccesLevel(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO AccessLevel VALUES (%1,'%2')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toString()));
}

datamap Users::getUserAccess()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM UserAccess");
    while (sqlQuery_->next())
    {
        value.clear();

        if(data.find(sqlQuery_->value(0).toInt()) != data.end())
        {
            value = data[sqlQuery_->value(0).toInt()];
        }

        value << QVariant(sqlQuery_->value(1).toInt());

        data.insert(sqlQuery_->value(0).toInt(),value);


        qDebug() << "User Id" << sqlQuery_->value(0).toInt() <<
                    "Level Id" << QVariant(sqlQuery_->value(1).toInt());
    }
    return data;
}

bool Users::setUserAcces(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO UserAccess VALUES (%1,%2)") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()));
}

bool Users::deleteUserAcces(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("DELETE FROM UserAccess WHERE UserId = %1 AND LevelId = %2") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()));
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

    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'AccessLevel'"
                              "('LevelId' INTEGER PRIMARY KEY,"
                              "'LevelName' TEX T NOT NULL UNIQUE)");


    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'UserAccess'"
                              "('UserId' INTEGER ,"
                              "'LevelId' INTEGER ,"
                              "PRIMARY KEY ('UserId', 'LevelId'))");
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

datamap DatabaseEngine::getUsers()
{

    return users_->getUsers();
}

bool DatabaseEngine::setUser(QList<QVariant> data)
{
    bool result =  users_->setUser(data);
    if(result)
    {
        emit userChanged();
    }
    return result;
}

bool DatabaseEngine::deleteUser(QList<QVariant> data)
{
    return users_->deleteUser(data);
}

datamap DatabaseEngine::getAceesLevels()
{
    return users_->getAceesLevels();
}

bool DatabaseEngine::setAccesLevel(QList<QVariant> data)
{
    bool result = users_->setAccesLevel(data);

    if(result)
    {
        emit accessLevelChanged();
    }
    return result;
}

datamap DatabaseEngine::getUserAccess()
{
    return users_->getUserAccess();
}

bool DatabaseEngine::deleteUserAcces(QList<QVariant> data)
{
    return users_->deleteUserAcces(data);
}

void DatabaseEngine::slotSetUsers(QString nick, QString fullname, QString pass)
{
    QList<QVariant> datos;
    datos.append(1, nick, fullname, pass);
    setUser(datos);
}

bool DatabaseEngine::setUserAcces(QList<QVariant> data)
{
    bool result =  users_->setUserAcces(data);
    if(result)
    {
        emit userAccessChanged();
    }
    return result;
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



