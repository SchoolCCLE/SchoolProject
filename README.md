SchoolPrinter
=============

Master Project for School Printer
<<<<<<< HEAD
Team3
=======
All Teams must have a branch Named TeamX


Vamos a desarrollar un programa modular, donde iremos incrementando la funcionalidad del mismo dia a dia.

El programa viene con un modulo creado que gestiona la conexion con una base de datos en SQLITE, que hara de pasarela entre la base de datos y el programa.

Sera necesario crear solo la Clase DatabaseEngine
Si existe algun bug dentro de esta clase(espero que no) avisar al profesor y lo intentaremos solucionar lo mas rapido posible.


Especificaciones del proyecto
Dia 1
Crear una aplicacion en QT que:
  Te pida un login de accesso
    Si no existe ningun usuario sera necesario crearlo.
  Crear una pantalla de gestion de usuarios
    Liste todos los usuarios que hay dados de alta en el sistema
    Cada usuario tendra, nickname, Full name y password
    El password tendra que ser almacenado a modo de hash, el que querais(MD4, sha...)
    El usuario tendra un nivel de acesso, y existiral al menos dos.
      1 - Llamado Admin, que te permitira añadir usuarios
      2 - Llamado user que te permitira acesso al sistema, y consulta de usuario, pero no añadir o cmabiar datos del usuario
    Los Admins podran dar de alta, borrar o modificar datos de usuario, pero no puede borrarse a si mismo.

La base de datos por defeto esta vacia, sera responsabilidad del programa gestionar que pasa cuando no hay ningun usuario creado en el sistema.
    
>>>>>>> 57386af13535d7ca40cced6490946f6f7cb655e0
