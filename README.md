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
  
  
Day 3
  Crearemos de nuevo los branch, ahora los llamaremos Day3_TeamX

A partir del projecto ya creado se requiere
  1) Crear una clase PrinterEngine que sea capaz de emitir señales y contener slots
    Contendra el stado actual de la impresora[Idle,printing,warnig,error], en modo numerico y en modo texto, con el mensaje       que se crea oportuno.
    Un campo que nos diga el tiempo que lleva funcionando la impresora(desde el arranque del programa)
    Un campo que nos diga el tipo de impresora que es(Alta capacidad o baja capacidad)
    Los setters y getters necesarios para setear estos campos(El de tipo de impresora se hara obligatoriamente en el              constructor)
    2) Crear una pantalla llamada Cartridges.qml que contendra una lista(en modo grafico) de los cartridges de la impresora, la       de alta capacidad tendra 8 cartridges,(2 para cada color CMYK) y la de baja capacidad solo 1 cartridges por color.
      Los cartridges tendran los siguientes campos.
        Id
        Color, un color de CMYK
        Nivel Tinta
        Cpacidad de tinta
        Fecha de instalacion
      El Estado del Cartridges puede ser ok, warning, o error, y se tiene que representar con un icono dentro del cartridge
      Sera Warning cuando la tinta este a menos de 5%
      Sera error cuando la tinta esta al 0%
      El resto de los casos sera ok
      El estado del cartridge, modifica el estado de la impresora.
      E nivel de tinta se representara graficamente.
  
Dia 4
  Crearemos de nuevo el branch a partir del master.
  Tendremos el codigo de vuestros compañeros de Team 4, con algunos retoques que hice.
  
  El proyecto consta de crear un Gestor de jobs. Los jobs son archivos que se envian para imprimir.
  
  Se requiere de una pantalla que contenga dos pestañas (Tabs) una con una lista de los jobs que se estan imprimiendo, y otra con una lista de los jobs impresos
    Un Job Consta de 
        Int JobId
        Int Type //Tipo del fichero (pdf,jpg.....)
        Name     //Nombre del fichero sin extension
        Tiempo de impresion //El tiempo necesario para imprimirlo, al crearlo sera u numero aleatorio entre 15 y 180 segundos)
        Estado //Estado del Job(solo puede ser,,, Esperando a imprimir, imprimiendo, impreso)
        C //Tinta Cyan consumida en mm (Sera un aleatorio entre 100 y 1000
        M //Tinta Magenta consumida en mm (Sera un aleatorio entre 100 y 1000
        Y //Tinta Yellow consumida en mm (Sera un aleatorio entre 100 y 1000
        K //Tinta Black consumida en mm (Sera un aleatorio entre 100 y 1000
  
    Tendremos un footer con un boton que mostrara un dialogo, donde podras escoger un fichero del sistema, solo ficheros pdf, jpg, png, tiff.
    El fichero pasara a la lista de jobs.  
  
  En la pestaña de jobs imprimiendose tendremos un boton(PLAY/PAUSE) que detendra los jobs pendientes de imprimir(el job que se esta imprimiendo se terminara de imprimir), o reanudara otra vez la impresora.
  Solo se permite usar una palabra en el boton, o play o pause. Podeis usar otro tipo de controloles, como RAdio Buttons o lo que considereis mas apropiados.
  
  En la pestaña de jobs impresos tendremos un boton (Delete All) que borrara todos los jobs impresos(Solo los impresos), PEro antes nos pedira confirmacion para hacerlo con un dialogo.
  
  
  Las listas contendran por lo menos la siguiente informacion
    Un icono con el tipo de fichero
    El nombre del Job
    El tiempo del job(si esta esperando a imprimir o si esta impreso) el tiempo restante de impresion(Si se esta imprimiendo)
    Un icono pequeñito con el estado(un relog si esta esperando a imprimir, una flecha verde de "PLAY" si se esta imprimiendo, Un tick verde si esta impreso
    
    Al pulsar en un Job de la lista se mostrara una pantalla con toda la informacion, y un boton de borrado, que borrara el job, previo dialogo de confirmacion.
  
  Pistas:::::::
  Necesitais una clase Job, con toda la informacion que considereis oportuna
  Necesitareis refrescar el estado de los jobs, cada segundo esta bien, para que se decremente el tiempo restante de impresion y el estado del job cuando se imprime.
  Por Favor, Por Favor, Por Favor, Leer la documentaciond e QTimer, y de como se empieza el el timer y cuando se apaga.
  Y si, vuestros temores son ciertos, cada Job necesita su propio QTimer, y hay que pararlo alguna vez.
  
  
  Otra Pista:::::::: TabView. Ahi lo dejamos.
  
  Enjoy.
  
