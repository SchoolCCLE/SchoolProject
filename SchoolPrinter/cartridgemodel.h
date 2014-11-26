#ifndef CARTRIDGEMODEL_H
#define CARTRIDGEMODEL_H
#include <QtQml>
#include <QObject>
#include <QTime>

class CartridgeModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(int numberStatus READ getNumberStatus WRITE setNumberStatus NOTIFY numberStatusChanged)
    Q_PROPERTY(QString idColor READ idcolor WRITE setIdColor NOTIFY idColorChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(int capacity READ capacity WRITE setCapacity NOTIFY capacityChanged)
    Q_PROPERTY(QDateTime installDate READ installDate WRITE setInstallDate NOTIFY installDateChanged)

    Q_ENUMS(Status)

public:
    enum Status {
        OK,
        WARNING,
        ERROR
    };

    explicit CartridgeModel(QString color, QObject *parent = 0);
/*
    static void declareQML()
    {
        qmlRegisterType<CartridgeModel>("MyQMLEnums",1,0,"Status");
    }
*/
    Status status() const;

    QString color() const;

    int level() const;

    QDateTime installDate() const;

    QString idcolor() const
    {
        return m_idColor;
    }

    QString getDateTime() { return m_installDate.toString(); }

    int capacity() const { return m_capacity; }

    int getNumberStatus() const
    {
        return m_numberStatus;
    }

signals:

    void statusChanged(Status arg);

    void colorChanged(QString arg);

    void levelChanged(int arg);

    void installDateChanged(QDateTime arg);

    void idColorChanged(QString arg);

    void capacityChanged(int arg);

    void numberStatusChanged(int arg);

public slots:

    void setStatus(Status arg);
    void setColor(QString arg);

    void setLevel(int arg);

    void setInstallDate(QDateTime arg);

    void setIdColor(QString arg)
    {
        if (m_idColor == arg)
            return;

        m_idColor = arg;
        emit idColorChanged(arg);
    }

    void setCapacity(int arg)
    {
        if (m_capacity == arg)
            return;

        m_capacity = arg;
        emit capacityChanged(arg);
    }

    void setNumberStatus(int arg)
    {
        if (m_numberStatus == arg)
            return;

        m_numberStatus = arg;
        emit numberStatusChanged(arg);
    }

private:
    Status m_status;

    QString m_color;

    int m_level;

    QDateTime m_installDate;

    QString m_idColor;
    int m_capacity;
    int m_numberStatus;
};

#endif // CARTRIDGEMODEL_H
