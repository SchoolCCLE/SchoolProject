#ifndef USER_H
#define USER_H

#include <QString>

class User
{

public:
    User(){}
    User(QString nickName, QString fullName, QString password, short level);

    ~User(){}

    QString getNickName() { return nickName_; }
    void setNickName(QString nickName) { nickName_ = nickName; }

    QString getFullName() { return fullName_; }
    void setFullName(QString fullName) { fullName_ = fullName; }

    QString getPassword() { return password_; }
    void setPassword(QString password) { password_ = password; }

    short getLevel() { return level_; }
    void setLevel(short level) { level_ = level; }

private:
    QString nickName_;
    QString fullName_;
    QString password_;
    short level_;
};

#endif // USER_H
