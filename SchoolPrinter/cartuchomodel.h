#ifndef CARTUCHOMODEL_H
#define CARTUCHOMODEL_H

#include <QObject>
#include <QString>
#include <QDateTime>

/**
 * @brief The CartuchoModel class
 * author Roberto de Castro
 */
class CartuchoModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(int capacity READ capacity WRITE setCapacity NOTIFY capacityChanged)
    Q_PROPERTY(QDateTime installDate READ installDate WRITE setInstallDate NOTIFY installDateChanged)
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)

public:
    explicit CartuchoModel(QString color, QObject *parent = 0);

    QString status() const;
    QString color() const;
    int level() const;
    int capacity() const;
    QDateTime installDate() const;
    QString image() const;

signals:
    void statusChanged(QString arg);
    void colorChanged(QString arg);
    void levelChanged(int arg);
    void capacityChanged(int arg);
    void installDateChanged(QDateTime arg);
    void imageChanged(QString arg);

public slots:

    void setStatus(QString arg);
    void setColor(QString arg);
    void setLevel(int arg);
    void setCapacity(int arg);
    void setInstallDate(QDateTime arg);
    void setImage(QString arg);

private:
    static int id;
    QString m_status;
    QString m_color;
    int m_level;
    int m_capacity;
    QDateTime m_installDate;
    QString m_image;
};

#endif // CARTUCHOMODEL_H
