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

/**
 * @brief The Users class provide information about the user present into application
 */
class Users : public QObject
{
    Q_OBJECT
public:
    static Users* getInstance();
    virtual ~Users() {}
private:
    Users(QObject* parent=0);
    QMap<int, QList<QVariant> > userList_;
};


class DatabaseEngine : public QObject
{
    Q_OBJECT
public:
    static DatabaseEngine * getInstance();

signals:

public slots:
private:
    explicit DatabaseEngine(QObject *parent = 0);
    Users* users_;
    QSqlDatabase dataBase_;

    bool openDB();
    bool deleteDB();
    QSqlError lastError();
};

#endif // DATABASEENGINE_H
