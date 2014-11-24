#ifndef USUARIO_H
#define USUARIO_H

#include <QString>
#include <QList>

/**
 * @brief The Usuario class
 * @author Roberto de Castro
 */
class Usuario
{
public:
    Usuario();

    /**
     * @brief getId. Getter user id
     * @return user's id
     */
    int getId() const;
    /**
     * @brief setId. Setter user id
     * @param value
     */
    void setId(int value);
    /**
     * @brief getNick. Getter user nick
     * @return user's nick
     */
    QString getNick() const;
    /**
     * @brief setNick. Setter user nick
     * @param value
     */
    void setNick(const QString &value);
    /**
     * @brief getFullName Getter user full name
     * @return user's full name
     */
    QString getFullName() const;
    /**
     * @brief setFullName Setter user full name
     * @param value
     */
    void setFullName(const QString &value);
    /**
     * @brief getPassword Getter user password
     * @return passsword user
     */
    QString getPassword() const;
    /**
     * @brief getPasswordHash Getter user password
     * @return passsword user in hash format
     */
    QString getPasswordHash() const;
    /**
     * @brief setPassword. Setter user's password
     * @param value
     */
    void setPassword(const QString &value);
    /**
     * @brief getRollList Getter roll list
     * @return list with user's rolles
     */
    QList<QString> getRollList() const;
    /**
     * @brief setRollList. Setter roll list
     * @param value
     */
    void setRollList(const QList<QString> &value);
    /**
     * @brief addRoll Adds new roll for the user
     * @param roll
     */
    void addRoll(QString roll);
    /**
     * @brief getRoll Gett roll stored in list
     * @param position
     * @return roll stores in list position
     */
    QString getRoll(int position);

private:
    /**
     * @brief id. User's identfier
     */
    int id;
    /**
     * @brief nick. User's nick
     */
    QString nick;
    /**
     * @brief fullName. User's full name
     */
    QString fullName;
    /**
     * @brief password. User's password
     */
    QString password;
    /**
     * @brief rollList. List in which store user rolls
     */
    QList<QString> rollList;
};

#endif // USUARIO_H
