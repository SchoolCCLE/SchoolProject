#include "databaseengine.h"
#include <assert.h>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>

Users *Users::getInstance()
{
    static Users* theInstance = new Users();
    return theInstance;
}

void Users::setDatabase(QSqlDatabase dataBase)
{
    dataBase_ = dataBase;
    sqlQuery_ = new QSqlQuery(dataBase_);
    qDebug () << "Created tables users" << createTables();
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

datamap Users::getAccessLevels()
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

bool Users::setAccessLevel(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO AccessLevel VALUES (%1,'%2')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toString()));
}

bool Users::deleteAccessLevel(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("DELETE FROM AccessLevel WHERE LevelId = %1").arg(data.at(0).toInt()));
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

bool Users::setUserAccess(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO UserAccess VALUES (%1,%2)") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()));
}

bool Users::deleteUserAccess(QList<QVariant> data)
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
                              "'LevelName' TEXT NOT NULL UNIQUE)");


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
    bool result =  users_->deleteUser(data);
    if(result)
    {
        emit userChanged();
    }
    return result;
}

datamap DatabaseEngine::getAccessLevels()
{
    return users_->getAccessLevels();
}

bool DatabaseEngine::setAccessLevel(QList<QVariant> data)
{
    bool result = users_->setAccessLevel(data);

    if(result)
    {
        emit accessLevelChanged();
    }
    return result;
}

bool DatabaseEngine::deleteAccessLevel(QList<QVariant> data)
{
    bool result = users_->deleteAccessLevel(data);

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

bool DatabaseEngine::deleteUserAccess(QList<QVariant> data)
{
    bool result= users_->deleteUserAccess(data);
    if(result)
    {
        emit userAccessChanged();
    }
    return result;

}

datamap DatabaseEngine::getPrintheads()
{
    return printheads_->getPrintheads();
}

bool DatabaseEngine::setPrinthead(Printheads::BBDDPrinthead p)
{
    bool result = printheads_->setPrinthead(p);
    if (result)
    {
        emit printheadChanged();
    }
    return result;
}

bool DatabaseEngine::deletePrinthead(QList<QVariant> data)
{
    bool result = printheads_->deletePrinthead(data);

    if(result)
    {
        emit printheadChanged();
    }
    return result;
}

datamap DatabaseEngine::getCartridges()
{
    return cartridges_->getCartridges();
}

bool DatabaseEngine::setCartridge(Cartridges::BBDDCartridges c)
{
    bool result = cartridges_->setCartridges(c);
    if (result)
    {
        emit cartridgesChanged();
    }
    return result;
}

bool DatabaseEngine::deleteCartridge(QList<QVariant> data)
{
    bool result = cartridges_->deleteCartridge(data);

    if(result)
    {
        emit cartridgesChanged();
    }
    return result;
}

datamap DatabaseEngine::getJobs()
{
    return jobManager_->getJobs();
}

bool DatabaseEngine::newJob(JobManager::BBDDJob data)
{
    bool result =  jobManager_->newJob(data);
    if(result)
    {
        emit jobManagerChanged();
    }
    return result;
}

bool DatabaseEngine::updateJob(JobManager::BBDDJob data)
{
    bool result =  jobManager_->updateJob(data);
    if(result)
    {
        emit jobManagerChanged();
    }
    return result;
}

bool DatabaseEngine::deleteJob(QList<QVariant> data)
{
    bool result =  jobManager_->deleteJob(data);
    if(result)
    {
        emit jobManagerChanged();
    }
    return result;
}

bool DatabaseEngine::setUserAccess(QList<QVariant> data)
{
    bool result =  users_->setUserAccess(data);
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

    printheads_ = Printheads::getInstance();
    printheads_->setParent(this);
    printheads_->setDatabase(dataBase_);

    cartridges_ = Cartridges::getInstance();
    cartridges_->setParent(this);
    cartridges_->setDatabase(dataBase_);

    jobManager_ = JobManager::getInstance();
    jobManager_->setParent(this);
    jobManager_->setDatabase(dataBase_);

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

Printheads *Printheads::getInstance()
{
    static Printheads *instance = new Printheads();
    return instance;
}

datamap Printheads::getPrintheads()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM Printheads");
    while (sqlQuery_->next())
    {
        value.clear();
        value << QVariant(sqlQuery_->value(1).toInt()) <<
                 QVariant(sqlQuery_->value(2).toInt()) <<
                 QVariant(sqlQuery_->value(3).toInt()) <<
                 QVariant(sqlQuery_->value(4).toDateTime());

        data.insert(sqlQuery_->value(0).toInt(),value);

        qDebug() << "PrintheadID " << sqlQuery_->value(0).toInt() <<
                    "color " << QVariant(sqlQuery_->value(1).toInt()) <<
                    "health " << QVariant(sqlQuery_->value(2).toInt()) <<
                    "warranty " << QVariant(sqlQuery_->value(3).toInt()) <<
                    "installation " << QVariant(sqlQuery_->value(4).toDateTime());
    }
    return data;
}

bool Printheads::setPrinthead(Printheads::BBDDPrinthead data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO Printheads VALUES (%1,'%2','%3','%4','%5')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()) \
                           .arg(data.at(2).toInt()) \
                           .arg(data.at(3).toInt()) \
                           .arg(data.at(4).toString()));
}

bool Printheads::deletePrinthead(Printheads::BBDDPrinthead data)
{
    return sqlQuery_->exec(QString("DELETE FROM Printheads WHERE PrintheadID = %1").arg(data.at(0).toInt()));
}

Printheads::Printheads(QObject *parent) : QObject(parent),sqlQuery_(NULL)
{

}

void Printheads::setDatabase(QSqlDatabase dataBase)
{
    dataBase_ = dataBase;
    sqlQuery_ = new QSqlQuery(dataBase_);
    qDebug () << "Created table printheads" << createTables();
}

bool Printheads::createTables()
{
    assert( dataBase_.isOpen() );
    assert(sqlQuery_);

    bool result = true;

    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'Printheads'"
                              "('PrintheadID'  INTEGER PRIMARY KEY,"
                              "'color' INTEGER,"
                              "'health' INTEGER,"
                              "'warranty' INTEGER,"
                              "'installation' TEXT)");

    return result;
}

////////////////////////////// Cartridges //////////////////////////////
Cartridges *Cartridges::getInstance()
{
    static Cartridges *instance = new Cartridges();
    return instance;
}

datamap Cartridges::getCartridges()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM Cartridges");
    while (sqlQuery_->next())
    {
        value.clear();
        value << QVariant(sqlQuery_->value(1).toInt()) <<
                 QVariant(sqlQuery_->value(2).toInt()) <<
                 QVariant(sqlQuery_->value(3).toInt()) <<
                 QVariant(sqlQuery_->value(4).toDateTime());

        data.insert(sqlQuery_->value(0).toInt(),value);

        qDebug() << "CartridgeID " << sqlQuery_->value(0).toInt() <<
                    "color " << QVariant(sqlQuery_->value(1).toInt()) <<
                    "inkLevel " << QVariant(sqlQuery_->value(2).toInt()) <<
                    "inkCapacity " << QVariant(sqlQuery_->value(3).toInt()) <<
                    "installation " << QVariant(sqlQuery_->value(4).toDateTime());
    }
    return data;
}

bool Cartridges::setCartridges(Cartridges::BBDDCartridges data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO Cartridges VALUES (%1,'%2','%3','%4','%5')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()) \
                           .arg(data.at(2).toInt()) \
                           .arg(data.at(3).toInt()) \
                           .arg(data.at(4).toString()));
}

bool Cartridges::deleteCartridge(Cartridges::BBDDCartridges data)
{
    return sqlQuery_->exec(QString("DELETE FROM Cartridges WHERE CartridgeID = %1").arg(data.at(0).toInt()));
}

Cartridges::Cartridges(QObject *parent) : QObject(parent),sqlQuery_(NULL)
{

}

void Cartridges::setDatabase(QSqlDatabase dataBase)
{
    dataBase_ = dataBase;
    sqlQuery_ = new QSqlQuery(dataBase_);
    qDebug () << "Created table cartridges" << createTables();
}

bool Cartridges::createTables()
{
    assert( dataBase_.isOpen() );
    assert(sqlQuery_);

    bool result = true;

    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'Cartridges'"
                              "('CartrigesID'  INTEGER PRIMARY KEY,"
                              "'color' INTEGER,"
                              "'inkLevel' INTEGER,"
                              "'inkCapacity' INTEGER,"
                              "'installation' TEXT)");

    return result;
}

////////// Job manager //////

JobManager *JobManager::getInstance()
{
    static JobManager *instance = new JobManager();
    return instance;
}

datamap JobManager::getJobs()
{
    datamap data;
    QList<QVariant> value;
    sqlQuery_->exec("SELECT * FROM JobManager");
    while (sqlQuery_->next())
    {
        value.clear();
        value << QVariant(sqlQuery_->value(1).toInt()) <<
                 QVariant(sqlQuery_->value(2).toString()) <<
                 QVariant(sqlQuery_->value(3).toInt()) <<
                 QVariant(sqlQuery_->value(4).toInt()) <<
                 QVariant(sqlQuery_->value(5).toInt()) <<
                 QVariant(sqlQuery_->value(6).toInt()) <<
                 QVariant(sqlQuery_->value(7).toInt()) <<
                 QVariant(sqlQuery_->value(8).toInt());



        data.insert(sqlQuery_->value(0).toInt(),value);

        qDebug() << "JobID " << sqlQuery_->value(0).toInt() <<
                    "Type " << QVariant(sqlQuery_->value(1).toInt()) <<
                    "Name " << QVariant(sqlQuery_->value(2).toInt()) <<
                    "PrintTime " << QVariant(sqlQuery_->value(3).toInt()) <<
                    "Status " << QVariant(sqlQuery_->value(4).toInt()) <<
                    "C " << QVariant(sqlQuery_->value(5).toInt()) <<
                    "M " << QVariant(sqlQuery_->value(6).toInt()) <<
                    "Y " << QVariant(sqlQuery_->value(7).toInt()) <<
                    "K " << QVariant(sqlQuery_->value(8).toInt());
    }
    return data;
}

bool JobManager::newJob(JobManager::BBDDJob data)
{

    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO JobManager VALUES (NULL,%1,'%2','%3','%4','%5','%6','%7','%8')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toString()) \
                           .arg(data.at(2).toInt()) \
                           .arg(data.at(3).toInt()) \
                           .arg(data.at(4).toInt()) \
                           .arg(data.at(5).toInt()) \
                           .arg(data.at(6).toInt()) \
                           .arg(data.at(7).toInt()));
}

bool JobManager::updateJob(JobManager::BBDDJob data)
{
    return sqlQuery_->exec(QString("INSERT OR REPLACE INTO JobManager VALUES (%1,'%2','%3','%4','%5','%6','%7','%8', '%9')") \
                           .arg(data.at(0).toInt()) \
                           .arg(data.at(1).toInt()) \
                           .arg(data.at(2).toString()) \
                           .arg(data.at(3).toInt()) \
                           .arg(data.at(4).toInt()) \
                           .arg(data.at(5).toInt()) \
                           .arg(data.at(6).toInt()) \
                           .arg(data.at(7).toInt()) \
                           .arg(data.at(8).toInt()));
}

bool JobManager::deleteJob(QList<QVariant> data)
{
    return sqlQuery_->exec(QString("DELETE FROM JobManager WHERE JobId = %1").arg(data.at(0).toInt()));
}

JobManager::JobManager(QObject *)
{

}

void JobManager::setDatabase(QSqlDatabase dataBase)
{
    dataBase_ = dataBase;
    sqlQuery_ = new QSqlQuery(dataBase_);
    qDebug () << "Created table JobManager" << createTables();
}

bool JobManager::createTables()
{
    assert( dataBase_.isOpen() );
    assert(sqlQuery_);

    bool result = true;

    result |= sqlQuery_->exec("CREATE TABLE IF NOT EXISTS 'JobManager'"
                              "('JobId'  INTEGER PRIMARY KEY,"
                              "'Type' INTEGER,"
                              "'Name' STRING,"
                              "'PrintTime' INTEGER,"
                              "'Status' INTEGER,"
                              "'C' INTEGER,"
                              "'M' INTEGER,"
                              "'Y' INTEGER,"
                              "'K' INTEGER)");

    return result;
}
