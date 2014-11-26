#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include <QObject>
#include <QDateTime>
class Cartridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int statusCart READ getStatusCart WRITE setStatusCart NOTIFY statusCartChanged)
    Q_PROPERTY(QString colorCart READ getColorCart WRITE setColorCart NOTIFY colorCartChanged)
    Q_PROPERTY(int healthCart READ getHealthCart WRITE setHealthCart NOTIFY healhCartChanged)
    Q_PROPERTY(bool warrantyCart READ getWarrantyCart WRITE setWarrantyCart NOTIFY warrantyCartChanged)
    Q_PROPERTY(QDateTime installDateCart READ getDateCart WRITE setDateCart NOTIFY dateCartChanged)


public:






Cartridge();
Cartridge(QString color);



int getStatusCart() const
{
    return m_statusCart;
}
QString getColorCart() const
{
    return m_colorCart;
}

int getHealthCart() const
{
    return m_healthCart;
}

bool getWarrantyCart() const
{
    return m_warrantyCart;
}

QDateTime getDateCart() const
{
    return m_installDateCart;
}

public slots:
void setStatusCart(int arg)
{
    if (m_statusCart == arg)
        return;

    m_statusCart = arg;
    emit statusCartChanged(arg);
}
void setColorCart(QString arg)
{
    if (m_colorCart == arg)
        return;

    m_colorCart = arg;
    emit colorCartChanged(arg);
}

void setHealthCart(int arg)
{
    if (m_healthCart == arg)
        return;

    m_healthCart = arg;
    emit healhCartChanged(arg);
}

void setWarrantyCart(bool arg)
{
    if (m_warrantyCart == arg)
        return;

    m_warrantyCart = arg;
    emit warrantyCartChanged(arg);
}

void setDateCart(QDateTime arg)
{
    if (m_installDateCart == arg)
        return;

    m_installDateCart = arg;
    emit dateCartChanged(arg);
}

signals:
void statusCartChanged(int arg);
void colorCartChanged(QString arg);
void healhCartChanged(int arg);
void warrantyCartChanged(bool arg);
void dateCartChanged(QDateTime arg);
private:
int m_statusCart;

QString m_colorCart;

int m_healthCart;

bool m_warrantyCart;

QDateTime m_installDateCart;
};

#endif // CARTRIDGE_H
