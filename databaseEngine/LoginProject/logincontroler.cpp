#include "logincontroler.h"

LoginControler::LoginControler(QObject *parent) :
    QObject(parent)
{
    myBBDD = DatabaseEngine::getInstance();



}

bool LoginControler::comprobarDatos(QString _nick, QString _pass)
{
    datamap myListOfUsers;
    myListOfUsers = myBBDD->getUsers();

    for(int i=0; i<myListOfUsers.size();++i){

        if (_nick == myListOfUsers[i].at(1)){
            if (passwordToHash(_pass)==myListOfUsers[i].at(3)){

                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;


}

QString LoginControler::passwordToHash(QString pass)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(pass.toUtf8());
    return hash.result().toHex();

}

bool LoginControler::estaVaciaBBDD()
{
    datamap myListOfUsers;
    myListOfUsers = myBBDD->getUsers();
    if (myListOfUsers.empty()){
        return true;
    }
    else {
        return false;
    }

}
