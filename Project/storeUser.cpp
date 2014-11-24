#include "storeUser.h"

StoreUser::StoreUser(QString nickName, QString fullName, QString password, short level)
{
    nickName_ = nickName;
    fullName_ = fullName;
    password_ = password;
    level_ = level;
}
