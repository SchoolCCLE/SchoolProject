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
    bool deleteUser(QList<QVariant> data);

    datamap getAceesLevels();
    bool setAccesLevel(QList<QVariant> data);

    datamap getUserAccess();
    bool setUserAcces(QList<QVariant> data);
    bool deleteUserAcces(QList<QVariant> data);

    virtual ~Users() {}
private:
    Users(QObject* parent=0);
    datamap userList_;
    QSqlDatabase dataBase_;
    QSqlQuery* sqlQuery_;

    bool createTables();
signals:

};


/**
 * @brief The DatabaseEngine class used to encapsulate action from a sqlite database.
 */
class DatabaseEngine : public QObject
{
    Q_OBJECT
public:


    /**
     * @brief getInstance
     * @return the instance of DatabaseEngine class
     */
    static DatabaseEngine * getInstance();

    /**
     * @brief ~DatabaseEngine This destructor close the database
     */
    virtual ~DatabaseEngine();

    /**
     * @brief closeDB, Close current dabatase
     * @return if can perform close database. Otherwise true
     */
    bool closeDB();

    /**
     * @brief getUsers Get Current user list.
     * Is  Map with integer as key, and QList of QVariant for value
     * The Key f the map is the user id
     *
     * List Values order
     *  [1] QString Name
     *  [2] QString Full Name
     *  [3] QString Password
     *
     * @return QMap<int, QList<QVariant> >
     */
    datamap getUsers();

    /**
     * @brief setUser set User data to database
     * @param data QList of QVariant
     *
     * List Values order
     *  [1] int     User Id
     *  [2] QString Name
     *  [3] QString Full Name
     *  [4] QString Password
     *
     * @return true if can perform the action. Otherwse false
     */
    bool setUser(QList<QVariant> data);

    /**
     * @brief deleteUser delete a user with certain id
     * @param data Qlist of QVariant with the id of the user
     * @return true if the action can be performed
     */
    bool deleteUser(QList<QVariant> data);

    /**
     * @brief getAceesLevels Get all acces levels
     * Is  Map with integer as key, and QList of QVariant for value
     * The Key f the map is the AccessLevel id
     *
     * List Values order
     *  [1] QString Name
     *
     * @return QMap<int, QList<QVariant> >
     */
    datamap getAceesLevels();

    /**
     * @brief setAccesLevel set Access Level data to database
     * @param data QList of QVariant
     *
     * List Values order
     *  [1] int     Access Level Id
     *  [2] QString Aceel Level Name
     *
     * The names are unique
     * @return true if can perform the action. Otherwse false
     */
    bool setAccesLevel(QList<QVariant> data);

    /**
     * @brief getUserAccess Get User acces levels
     * Is  Map with integer as key, and QList of QVariant for value
     * The Key of the map is the User id
     * The Value of map is a List of QVariant, with all access of the user.
     *
     * @return QMap<int, QList<QVariant> >
     */
    datamap getUserAccess();

    /**
     * @brief setUserAcces set Access Level for a certain user
     * @param data QList of QVariant
     *
     * List Values order
     *  [1] int User Level Id
     *  [2] int Access Level Id
     *
     * A user can have multiples access level
     * @return true if can perform the action. Otherwse false
     */
    bool setUserAcces(QList<QVariant> data);

    /**
     * @brief deleteUserAcces delete Access Level for a certain user
     * @param data QList of QVariant
     *
     * List Values order
     *  [1] int User Level Id
     *  [2] int Access Level Id
     *
     * delete a user access
     * @return true if can perform the action. Otherwse false
     */
    bool deleteUserAcces(QList<QVariant> data);

signals:
    void userChanged();
    void accessLevelChanged();
    void userAccessChanged();

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
