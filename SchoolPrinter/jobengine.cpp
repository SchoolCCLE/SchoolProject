#include "jobengine.h"

JobEngine::JobEngine(QObject *parent) :
    QObject(parent)
{
    qsrand(QTime::currentTime().msec());
}
