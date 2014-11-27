#include "jobengine.h"
#include <QDebug>

JobEngine::JobEngine(QObject *parent) :
    QObject(parent)
{
    qsrand(QTime::currentTime().msec());
    m_jobs.clear();
}

QStringList JobEngine::nombreFichero(QString _url)
{
    QString separator("/");
    QStringList fileName = _url.split(separator);
    QString name = fileName.last();
    fileName = name.split(".");

    return fileName;

}

void JobEngine::addNewJob(QString url)
{
    QStringList fileAndType;
    QString name, type;
    int type_number;
    fileAndType = nombreFichero(url);
    name = fileAndType.first();
    type = fileAndType.last();
    if (type == "pdf"){
        type_number = 1;
    }
    if (type == "jpg"){
        type_number = 2;
    }
    if (type == "png"){
        type_number = 3;
    }
    if (type == "tiff"){
        type_number = 4;
    }

    Job* newJob = new Job(type_number,name);
    m_jobs.append(newJob);


}
