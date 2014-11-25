#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QString>

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = 0);

    QString getState() const;
    void setState(const QString &value);

    QString getPrinterType() const;
    void setPrinterType(const QString &value);

    int getTimeWorking() const;
    void setTimeWorking(int value);

    QString formatTimeWorking();

private:

    QString state;
    int timeWorking; // seconds
    QString printerType;
    static int counterEvent;

signals:

public slots:

protected:
   void timerEvent(QTimerEvent *evt);

};

#endif // ENGINE_H
