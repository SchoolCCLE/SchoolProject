#ifndef PRINTERENGINE_H
#define PRINTERENGINE_H

#include <QObject>

class PrinterEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int stateNum READ getStateNum WRITE setStateNum NOTIFY stateNumChanged);
    int m_stateNum;
    Q_PROPERTY(QString stateText READ getStateText WRITE setStateText NOTIFY stateTextChanged);
    QString m_stateText;
    Q_PROPERTY(int tiempo READ getTiempo WRITE setTiempo NOTIFY tiempoChanged);
    int m_tiempo;

public:
    explicit PrinterEngine(int tipoImpresora, QObject* parent=0);
    QString tipo;

int getStateNum() const
{
    return m_stateNum;
}

QString getStateText() const
{
    return m_stateText;
}

int getTiempo() const
{
    return m_tiempo;
}

QString getTipo()
{
    return tipo;
}

signals:

void stateNumChanged(int arg);

void stateTextChanged(QString arg);

void tiempoChanged(int arg);

public slots:

void setStateNum(int arg)
{
    if (m_stateNum == arg)
        return;

    m_stateNum = arg;
    emit stateNumChanged(arg);
}
void setStateText(QString arg)
{
    if (m_stateText == arg)
        return;

    m_stateText = arg;
    emit stateTextChanged(arg);
}
void setTiempo(int arg)
{
    if (m_tiempo == arg)
        return;

    m_tiempo = arg;
    emit tiempoChanged(arg);
}

};

#endif // PRINTERENGINE_H
