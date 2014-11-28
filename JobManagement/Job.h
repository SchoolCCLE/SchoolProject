#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QDateTime>
#include <QTimer>

class Job : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int printTime READ getPrintTime WRITE setPrintTime NOTIFY printTimeChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool printed READ isPrinted WRITE setprinted NOTIFY printedChanged)
    Q_PROPERTY(QDateTime acquisitionTime READ getAcquisitionTime WRITE setAcquisitionTime NOTIFY acquisitionTimeChanged)
    Q_PROPERTY(bool printing READ isPrinting WRITE setPrinting NOTIFY printingChanged)
    Q_PROPERTY(TYPE type READ getType WRITE setType NOTIFY typeChanged)

public:
    explicit Job(QObject *parent = 0);

    enum TYPE {
        PDF,
        JPG,
        TIFF
    };
    Q_ENUMS(TYPE)

    int getId() const;

    int getPrintTime() const;

    QString getName() const;

    bool isPrinted() const;

    QDateTime getAcquisitionTime() const;

    bool isPrinting() const;

    TYPE getType() const;

signals:

    void idChanged(int arg);

    void printTimeChanged(int arg);

    void nameChanged(QString arg);

    void printedChanged(bool arg);

    void acquisitionTimeChanged(QDateTime arg);

    void printingChanged(bool arg);

    void typeChanged(TYPE arg);

public slots:

    void setId(int arg);

    void setPrintTime(int arg);

    void setName(QString arg);

    void setprinted(bool arg);

    void setAcquisitionTime(QDateTime arg);

    void updatePrinted();
    void setPrinting(bool arg);

    void setType(TYPE arg);

private:

    int id_;
    int printTime_;
    QString name_;
    bool printed_;
    QDateTime acquisitionTime_;
    bool printing_;

    QTimer* printingTimer_;
    TYPE type_;

private slots:
    void consumeTime();
};

#endif // JOB_H
