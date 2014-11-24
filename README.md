SchoolPrinter
=============

Master Project for School Printer
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
    

Dia 2
Crearemos de nuevo los branch, ahora los llamaremos Day2_TeamX

A partir del projecto ya creado se requiere
  1) Crear una clase PrinterEngine que sea capaz de emitir señales y contener slots
    Contendra el stado actual de la impresora[Idle,printing,warnig,error], en modo numerico y en modo texto, con el mensaje       que se crea oportuno.
    Un campo que nos diga el tiempo que lleva funcionando la impresora(desde el arranque del programa)
    Un campo que nos diga el tipo de impresora que es(Alta capacidad o baja capacidad)
    Los setters y getters necesarios para setear estos campos(El de tipo de impresora se hara obligatoriamente en el              constructor)
    
  2) Crear una HomeScreen.qml que sea la pantalla siguiente al loggin con exito
    HomeScreen.qml contara con un Header.qml que se colocara arriba del todo de la pantalla
    El Header.qml constara de: 
      Un icono que nos muestre el estado de la impresora colocade  a la izquierda del todo.
      Un texto que sera el estado de la impresora (Status Text) que ocupara todo lo ancho que pueda.
      Un boton que cierre la aplicacion colocado a la derecha del todo.
  3) En el cuerpo de la home screen habra 2 botones, para mostras dos pantallas distintas
     Una pantalla sera Printer.qml, que mostrara el estado actual de la printer, el tiempo que lleva encendida, y la lista de todos los usuarios y su nivel de accesso.
  4) Crear una pantalla llamada Printheads.qml que contendra una lista(en modo grafico) de los prinheads de la impresora, la       de alta capacidad tendra 8 pritnheads,(2 para cada color CMYK) y la de baja capacidad solo 1 printhead por color.
      Los printheads tendran los siguientes campos.
        Id
        Color, un color de CMYK
        Salud (de 0 a 100%)
        En Garantia(si o no)
        Fecha de instalacion
      El Estado del printhead puede ser ok, warning, o error, y se tiene que representar con un icono dentro del printhead
      Sera Error cuando la salud sea inferior a 10
      Sera Warning cuando la salud sea inferior a 35o La garantia haya expirado
      El resto de los casos sera ok
      El estado del printhead, modifica el estado de la impresora.
      
      
      Al pulsar en un prinhead, se abrira una pantalla PrintheadsDetails.qml, con todos los datos de ese printhead. 
  
  
  Notas: 
  Los printheads se cargaran al inicio del programa, dependiendo de si la printer es de alta capacidad o de baja capacidad.
  Si alguien acaba todo, tengo otro modulo para añadir.
  El Header.qml puede usarse en todas las pantallas excepto en la de PrintheadsDetails. He dicho puede, no es obligtorio.
  
  Enjoy
  
