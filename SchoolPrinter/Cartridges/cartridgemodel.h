#ifndef CARTRIDGEMODEL_H
#define CARTRIDGEMODEL_H

#include <QObject>

class CartridgeModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idColor READ idColor WRITE setIdColor NOTIFY idColorChanged)
    Q_PROPERTY(int inkLevel READ inkLevel WRITE setInkLevel NOTIFY inkLevelChanged)
    Q_PROPERTY(int inkCapacity READ inkCapacity WRITE setInkCapacity NOTIFY inkCapacityChanged)
    Q_PROPERTY(QDateTime * installationDate READ installationDate WRITE setInstallationDate NOTIFY installationDateChanged)

public:
    explicit CartridgeModel(QObject *parent = 0);


    int inkLevel() const
    {
        return m_inkLevel;
    }


    int idColor() const
    {
        return m_idColor;
    }

    int inkCapacity() const
    {
        return m_inkCapacity;
    }

    QDateTime * installationDate() const
    {
        return m_installationDate;
    }

public slots:
    void setInkLevel(int arg)
    {
        if (m_inkLevel == arg)
            return;

        m_inkLevel = arg;
        emit inkLevelChanged(arg);
    }

    void setIdColor(int arg)
    {
        if (m_idColor == arg)
            return;

        m_idColor = arg;
        emit idColorChanged(arg);
    }

    void setInkCapacity(int arg)
    {
        if (m_inkCapacity == arg)
            return;

        m_inkCapacity = arg;
        emit inkCapacityChanged(arg);
    }

    void setInstallationDate(QDateTime * arg)
    {
        if (m_installationDate == arg)
            return;

        m_installationDate = arg;
        emit installationDateChanged(arg);
    }

signals:
    void inkLevelChanged(int arg);

    void idColorChanged(int arg);

    void inkCapacityChanged(int arg);

    void installationDateChanged(QDateTime * arg);

private:

    int m_inkLevel;
    int m_idColor;
    int m_inkCapacity;
    QDateTime * m_installationDate;
};

#endif // CARTRIDGEMODEL_H
