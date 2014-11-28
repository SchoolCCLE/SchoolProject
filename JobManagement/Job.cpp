#include "Job.h"
#include <QtQml>
Job::Job(QObject *parent) :
    QObject(parent)
{
    setprinted(false);
    setPrinting(false);
    setAcquisitionTime(QDateTime::currentDateTime());

    printingTimer_ = new QTimer();
    connect(printingTimer_, SIGNAL(timeout()), this, SLOT(consumeTime()));


}

int Job::getId() const
{
    return id_;
}

int Job::getPrintTime() const
{
    return printTime_;
}

QString Job::getName() const
{
    return name_;
}

bool Job::isPrinted() const
{
    return printed_;
}

QDateTime Job::getAcquisitionTime() const
{
    return acquisitionTime_;
}

bool Job::isPrinting() const
{
    return printing_;
}

Job::TYPE Job::getType() const
{
    return type_;
}

void Job::setId(int arg)
{
    if (id_ != arg) {
        id_ = arg;
        emit idChanged(arg);
    }
}

void Job::setPrintTime(int arg)
{
    if (printTime_ != arg) {
        printTime_ = arg;
        emit printTimeChanged(arg);
    }
}

void Job::setName(QString arg)
{
    if (name_ != arg) {
        name_ = arg;
        emit nameChanged(arg);
    }
}

void Job::setprinted(bool arg)
{
    if (printed_ != arg) {
        printed_ = arg;
        emit printedChanged(arg);
    }
}

void Job::setAcquisitionTime(QDateTime arg)
{
    if (acquisitionTime_ != arg) {
        acquisitionTime_ = arg;
        emit acquisitionTimeChanged(arg);
    }
}

void Job::updatePrinted()
{
    setprinted(true);
}

void Job::setPrinting(bool arg)
{
    if (printing_ != arg) {
        printing_ = arg;
        emit printingChanged(arg);
    }
    if (printing_)
    {
        printingTimer_->start(1000);
    }
}

void Job::setType(Job::TYPE arg)
{
    if (type_ != arg) {
        type_ = arg;
        emit typeChanged(arg);
    }
}

void Job::consumeTime()
{
    printTime_--;
    if (printTime_ == 0)
    {
        printingTimer_->stop();
    }
    emit printTimeChanged(printTime_);
}
