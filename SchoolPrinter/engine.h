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

    QString getTimeWorking() const;
    void setTimeWorking(const QString &value);

    QString getPrinterType() const;
    void setPrinterType(const QString &value);

private:

    QString state;
    QString timeWorking;
    QString printerType;

signals:

public slots:

};

#endif // ENGINE_H
