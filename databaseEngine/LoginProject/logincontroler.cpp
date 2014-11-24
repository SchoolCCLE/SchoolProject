#include "logincontroler.h"

LoginControler::LoginControler(QObject *parent) :
    QObject(parent)
{
    myUsers = Users::getInstance();



}

bool LoginControler::comprobarDatos(QString _nick, QString _pass)
{
    datamap myListOfUsers;
    myListOfUsers = myUsers->getUsers();

    for(int i=0; i<myListOfUsers.size();++i){

        if (_nick == myListOfUsers[i].at(1)){
            if (passwordToHash(_pass)==myListOfUsers[i].at(3)){
                //emitir señal para cambiar de pantalla
            }
        }
    }


}
