#ifndef DATABASEENGINE_H
#define DATABASEENGINE_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include <QList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QString>

typedef QMap<int, QList<QVariant> > datamap;



/**
 * @brief The Users class provide information about the users
 */
class Users : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief getInstance. Instance of user
     * @return pointer to user
     */
    static Users* getInstance();

    /**
     * @brief setDatabase, Asign a database to user class where the data will be stored
     * @param dataBase
     */
    void setDatabase(QSqlDatabase dataBase);

    datamap getUsers();
    bool setUser(QList<QVariant> data);

    virtual ~Users() {}
private:
    Users(QObject* parent=0);
    datamap userList_;
    QSqlDatabase dataBase_;
    QSqlQuery* sqlQuery_;

    bool createTables();
signals:
    void userDataChanged();

};


class DatabaseEngine : public QObject
{
    Q_OBJECT
public:


    static DatabaseEngine * getInstance();
    virtual ~DatabaseEngine();
    bool closeDB();
signals:

public slots:
private:
    explicit DatabaseEngine(QObject *parent = 0);
    QString databaseName_;

    Users* users_;
    QSqlDatabase dataBase_;

    bool openDB();
    bool deleteDB();
    QSqlError lastError();
};

#endif // DATABASEENGINE_H
