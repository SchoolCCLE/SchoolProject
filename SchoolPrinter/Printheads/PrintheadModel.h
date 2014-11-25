#ifndef PRINTHEADMODEL_H
#define PRINTHEADMODEL_H

#include <QObject>

class PrintheadModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int health READ health WRITE setHealth NOTIFY healthChanged)
    Q_PROPERTY(bool warranty READ warranty WRITE setWarranty NOTIFY warrantyChanged)
    Q_PROPERTY(QDateTime* installDate READ installDate WRITE setInstallDate NOTIFY installDateChanged)

    Q_ENUMS(Status)
public:
    enum Status {
        OK,
        WARNING,
        ERROR
    };

    explicit PrintheadModel(QString color, QObject *parent = 0);

    Status status() const;

    QString color() const;

    int health() const;

    bool warranty() const;

    QDateTime *installDate() const;

signals:

    void statusChanged(Status arg);

    void colorChanged(QString arg);

    void healthChanged(int arg);

    void warrantyChanged(bool arg);

    void installDateChanged(QDateTime* arg);

public slots:

    void setStatus(Status arg);
    void setColor(QString arg);

    void setHealth(int arg);

    void setWarranty(bool arg);

    void setInstallDate(QDateTime *arg);

private:
    Status m_status;

    QString m_color;
    int m_health;
    bool m_warranty;
    QDateTime* m_installDate;
};

#endif // PRINTHEADMODEL_H
