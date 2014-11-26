#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <QObject>
#include <QString>

class Cartridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int level READ getLevel WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(int capacity READ getCapacity WRITE setCapacity NOTIFY capacityChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int cartridgeStatus READ getCartridgeStatus WRITE setCartridgeStatus NOTIFY cartridgeStatusChanged)
    int m_level;

    int m_capacity;

    QString m_color;

    int m_cartridgeStatus;

public:
    explicit Cartridge(QString col,int level,int capacity, QObject *parent = 0);

int getLevel() const
{
    return m_level;
}

int getCapacity() const
{
    return m_capacity;
}

QString getColor() const
{
    return m_color;
}

int getCartridgeStatus() const
{
    return m_cartridgeStatus;
}

signals:

void levelChanged(int arg);

void capacityChanged(int arg);

void colorChanged(QString arg);

void cartridgeStatusChanged(int arg);

public slots:

void setLevel(int arg)
{
    if (m_level == arg)
        return;

    m_level = arg;
    emit levelChanged(arg);
}
void setCapacity(int arg)
{
    if (m_capacity == arg)
        return;

    m_capacity = arg;
    emit capacityChanged(arg);
}
void setColor(QString arg)
{
    if (m_color == arg)
        return;

    m_color = arg;
    emit colorChanged(arg);
}
void setCartridgeStatus(int arg)
{
    if (m_cartridgeStatus == arg)
        return;

    m_cartridgeStatus = arg;
    emit cartridgeStatusChanged(arg);
}
};

#endif // CARTRIDGE_H
