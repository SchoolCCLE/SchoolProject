#include "controler.h"

Controler* Controler::controler_ = 0;

Controler::Controler()
{
    *dababaseEngine_ = DatabaseEngine::getInstance();
}

Controler *Controler::getInstance()
{
    if(controler_ == 0)
        controler_ = new Controler();

    return controler_;
}

void Controler::encode(QString cad)
{
    const char *pass = cad.toStdString().c_str();


    QCryptographicHash md5Generator(QCryptographicHash::Md5);
    md5Generator.addData( pass );

    qDebug() << md5Generator.result().toHex();
}


//SLOTS
void Controler::recibeUserIdentification(QString nickName, QString password)
{
    qDebug() << "The login of the user is "  << nickName;
    qDebug() << "The password of the user is " << password;

    encode(password);
}

