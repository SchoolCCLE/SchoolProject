#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDebug>
//Un Job Consta de Int JobId
//Int Type Tipo del fichero (pdf,jpg.....)
//Nombre del fichero sin extension Tiempo de impresion
//El tiempo necesario para imprimirlo, al crearlo sera u numero aleatorio entre 15 y 180 segundos)
//Estado del Job(solo puede ser,,, Esperando a imprimir, imprimiendo, impreso) C
//Tinta Cyan consumida en mm (Sera un aleatorio entre 100 y 1000 M
//Tinta Magenta consumida en mm (Sera un aleatorio entre 100 y 1000 Y
//Tinta Yellow consumida en mm (Sera un aleatorio entre 100 y 1000 K
//Tinta Black consumida en mm (Sera un aleatorio entre 100 y 1000

class Job : public QObject
{

    Q_OBJECT
    Q_PROPERTY(int jobId READ getJobId WRITE setJobId NOTIFY jobIdChanged)
    Q_PROPERTY(QString fileType READ getFileType WRITE setFileType NOTIFY fileTypeChanged)
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(int printingTime READ getPrintingTime WRITE setPrintingTime NOTIFY printingTimeChanged)
    Q_PROPERTY(QString jobStatus READ getJobStatus WRITE setJobStatus NOTIFY jobStatusChanged)
    Q_PROPERTY(int cyanInk READ getCyanInk WRITE setCyanInk NOTIFY cyanInkChanged)
    Q_PROPERTY(int magentaInk READ getMagentaInk WRITE setMagentaInk NOTIFY magentaInkChanged)
    Q_PROPERTY(int yellowInk READ getYellowInk WRITE setYellowInk NOTIFY yellowInkChanged)
    Q_PROPERTY(int blackInk READ getBlackInk WRITE setBlackInk NOTIFY blackInkChanged)

    int m_jobId;
    QString m_fileType;
    QString m_fileName;
    int m_printingTime;
    QString m_jobStatus;
    int m_cyanInk;
    int m_magentaInk;
    int m_yellowInk;
    int m_blackInk;
private:
    QTimer *timer;
public:
    explicit Job(QString fileURL, QObject *parent = 0);


int getJobId() const
{
    return m_jobId;
}

QString getFileType() const
{
    return m_fileType;
}

QString getFileName() const
{
    return m_fileName;
}

int getPrintingTime() const
{
    return m_printingTime;
}

QString getJobStatus() const
{
    return m_jobStatus;
}

int getCyanInk() const
{
    return m_cyanInk;
}

int getMagentaInk() const
{
    return m_magentaInk;
}

int getYellowInk() const
{
    return m_yellowInk;
}

int getBlackInk() const
{
    return m_blackInk;
}

signals:

void jobIdChanged(int arg);

void fileTypeChanged(QString arg);

void fileNameChanged(QString arg);

void printingTimeChanged(int arg);

void jobStatusChanged(QString arg);

void cyanInkChanged(int arg);

void magentaInkChanged(int arg);

void yellowInkChanged(int arg);

void blackInkChanged(int arg);

void printEnd();

public slots:

void setJobId(int arg)
{
    if (m_jobId == arg)
        return;

    m_jobId = arg;
    emit jobIdChanged(arg);
}
void setFileType(QString arg)
{
    if (m_fileType == arg)
        return;

    m_fileType = arg;
    emit fileTypeChanged(arg);
}
void setFileName(QString arg)
{
    if (m_fileName == arg)
        return;

    m_fileName = arg;
    emit fileNameChanged(arg);
}
void setPrintingTime(int arg)
{
    if (m_printingTime == arg)
        return;

    m_printingTime = arg;
    emit printingTimeChanged(arg);
}
void setJobStatus(QString arg)
{
    if (m_jobStatus == arg)
        return;

    m_jobStatus = arg;
    emit jobStatusChanged(arg);
}
void setCyanInk(int arg)
{
    if (m_cyanInk == arg)
        return;

    m_cyanInk = arg;
    emit cyanInkChanged(arg);
}
void setMagentaInk(int arg)
{
    if (m_magentaInk == arg)
        return;

    m_magentaInk = arg;
    emit magentaInkChanged(arg);
}
void setYellowInk(int arg)
{
    if (m_yellowInk == arg)
        return;

    m_yellowInk = arg;
    emit yellowInkChanged(arg);
}
void setBlackInk(int arg)
{
    if (m_blackInk == arg)
        return;

    m_blackInk = arg;
    emit blackInkChanged(arg);
}
void updatePrintingTime()
{
    if (m_jobStatus == "PRINTING"){
        if (m_printingTime == 0){
            timer->stop();
            setJobStatus("PRINTED");
            emit printEnd();
        }else{
            setPrintingTime(m_printingTime-1);
        }
    }
}
};


#endif // JOB_H
