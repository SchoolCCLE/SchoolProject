#include "job.h"

Job::Job(QObject *parent) : QObject(parent) {

    changePrintingTime(generateRandomNumber(180 ,15));

    changeCyan(generateRandomNumber(1000, 100) );
    changeMagenta(generateRandomNumber(1000, 100) );
    changeYellow(generateRandomNumber(1000, 100) );
    changeBlack(generateRandomNumber(1000, 100) );
}

QString Job::convertType() //pdf jpg png tiff
{
    if (m_type == 0)
        return "pdf";

    else if (m_type == 1)
        return "jpg";

    else if (m_type == 2)
        return "png";

    else if (m_type == 3)
        return "tiff";

    else
        return "Código incorrecto";
}

int Job::generateRandomNumber(int high, int low)
{
    int vuelta = 0;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    vuelta = qrand() % ( ( (high + 1) - low) + low );

    return vuelta;
}
