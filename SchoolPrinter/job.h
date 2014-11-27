#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QTime>

class Job : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int jobId READ getJobId WRITE setJobId NOTIFY jobIdChanged)
    Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int printingTime READ getPrintingTime WRITE setPrintingTime NOTIFY printingTimeChanged)
    Q_PROPERTY(QString state READ getState WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(int cyan READ getCyan WRITE setCyan NOTIFY cyanChanged)
    Q_PROPERTY(int magenta READ getMagenta WRITE setMagenta NOTIFY magentaChanged)
    Q_PROPERTY(int yellow READ getYellow WRITE setYellow NOTIFY yellowChanged)
    Q_PROPERTY(int black READ getBlack WRITE setBlack NOTIFY blackChanged)

    int m_jobId;

    int m_type;

    QString m_name;

    int m_printingTime;

    QString m_state;

    int m_cyan;

    int m_magenta;

    int m_yellow;

    int m_black;

public:
    explicit Job(QObject *parent = 0);

    QString convertType();

    int generateRandomNumber(int high, int low);

    int getJobId() const { return m_jobId; }

    int getType() const { return m_type; }

    QString getName() const { return m_name; }

    int getPrintingTime() const { return m_printingTime; }

    QString getState() const { return m_state; }

    int getCyan() const { return m_cyan; }

    int getMagenta() const { return m_magenta; }

    int getYellow() const { return m_yellow; }

    int getBlack() const { return m_black; }


    void changeJobId( int new_jobId ) { m_jobId = new_jobId; }

    void changType( int new_type ) { m_type = new_type; }

    void changeName( QString new_name ) { m_name = new_name; }

    void setPrintingTime( new_time ) { m_printingTime = time; }

    void setState( QString new_state ) { m_state = new_state; }

    void setCyan( int new_cyan ) { return m_cyan = new_cyan; }

    void setMagenta(int arg)
    {
        if (m_magenta == arg)
            return;

        m_magenta = arg;
        emit magentaChanged(arg);
    }

    void setYellow(int arg)
    {
        if (m_yellow == arg)
            return;

        m_yellow = arg;
        emit yellowChanged(arg);
    }

    void setBlack(int arg)
    {
        if (m_black == arg)
            return;

        m_black = arg;
        emit blackChanged(arg);
    }

signals:

    void jobIdChanged(int arg);

    void typeChanged(int arg);

    void nameChanged(QString arg);

    void printingTimeChanged(int arg);

    void stateChanged(QString arg);

    void cyanChanged(int arg);

    void magentaChanged(int arg);

    void yellowChanged(int arg);

    void blackChanged(int arg);

public slots:

    void setJobId(int arg)
    {
        if (m_jobId == arg)
            return;

        m_jobId = arg;
        emit jobIdChanged(arg);
    }

    void setType(int arg)
    {
        if (m_type == arg)
            return;

        m_type = arg;
        emit typeChanged(arg);
    }

    void setName(QString arg)
    {
        if (m_name == arg)
            return;

        m_name = arg;
        emit nameChanged(arg);
    }

    void setPrintingTime(int arg)
    {
        if (m_printingTime == arg)
            return;

        m_printingTime = arg;
        emit printingTimeChanged(arg);
    }

    void setState(QString arg)
    {
        if (m_state == arg)
            return;

        m_state = arg;
        emit stateChanged(arg);
    }

    void setCyan(int arg)
    {
        if (m_cyan == arg)
            return;

        m_cyan = arg;
        emit cyanChanged(arg);
    }

    void setMagenta(int arg)
    {
        if (m_magenta == arg)
            return;

        m_magenta = arg;
        emit magentaChanged(arg);
    }

    void setYellow(int arg)
    {
        if (m_yellow == arg)
            return;

        m_yellow = arg;
        emit yellowChanged(arg);
    }

    void setBlack(int arg)
    {
        if (m_black == arg)
            return;

        m_black = arg;
        emit blackChanged(arg);
    }
};

#endif // JOB_H

/*
 * Tiempo de impresion //El tiempo necesario para imprimirlo, al crearlo sera u numero aleatorio entre 15 y 180 segundos)
 * Estado //Estado del Job(solo puede ser,,, Esperando a imprimir, imprimiendo, impreso)
 * C //Tinta Cyan consumida en mm (Sera un aleatorio entre 100 y 1000
 * M //Tinta Magenta consumida en mm (Sera un aleatorio entre 100 y 1000
 * Y //Tinta Yellow consumida en mm (Sera un aleatorio entre 100 y 1000
 * K //Tinta Black consumida en mm (Sera un aleatorio entre 100 y 1000
 */
