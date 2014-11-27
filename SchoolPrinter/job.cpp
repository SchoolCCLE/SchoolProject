#include "job.h"
#include <QTime>
#include <QTimer>

Job::Job(QObject *parent) :
    QObject(parent)
{
    //Un Job Consta de Int JobId
    //Int Type Tipo del fichero (pdf,jpg.....)
    //Nombre del fichero sin extension Tiempo de impresion
    //El tiempo necesario para imprimirlo, al crearlo sera u numero aleatorio entre 15 y 180 segundos)
    //Estado del Job(solo puede ser,,, Esperando a imprimir, imprimiendo, impreso) C
    //Tinta Cyan consumida en mm (Sera un aleatorio entre 100 y 1000 M
    //Tinta Magenta consumida en mm (Sera un aleatorio entre 100 y 1000 Y
    //Tinta Yellow consumida en mm (Sera un aleatorio entre 100 y 1000 K
    //Tinta Black consumida en mm (Sera un aleatorio entre 100 y 1000

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    // Get random value between low-high
    // qrand() % ((high + 1) - low) + low

    m_jobId = 0;

//    setFileType();
//    setFileName();

    setJobStatus("PRINTING");
    setPrintingTime(qrand() % ((180 + 1) - 15) + 15);
    setCyanInk(qrand() % ((1000 + 1) - 100) + 100);
    setMagentaInk(qrand() % ((1000 + 1) - 100) + 100);
    setYellowInk(qrand() % ((1000 + 1) - 100) + 100);
    setBlackInk(qrand() % ((1000 + 1) - 100) + 100);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePrintingTime()));
    timer->start(1000);

}
