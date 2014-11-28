#include "JobGeneratorFake.h"
#include <QDebug>

JobGeneratorFake::JobGeneratorFake(QObject *parent) :
    QObject(parent)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    generatorTimer_ = new QTimer();
    generatorTimer_->setSingleShot(true);
    connect(generatorTimer_, SIGNAL(timeout()), this, SLOT(generateJob()));

}

void JobGeneratorFake::start()
{
    generatorTimer_->start((rand() % 10)*1000);
}

void JobGeneratorFake::stop()
{
    generatorTimer_->stop();
}

void JobGeneratorFake::generateJob()
{
    generatorTimer_->start((rand() % 10)*1000);
    Job* j = new Job();
    j->setName(generateTitle());
    j->setPrintTime(rand() % 10);

    int type = rand() % 3;
    qDebug() << "type " << type;
    switch (type) {
    case 0:
        j->setType(Job::PDF);
        break;
    case 1:
        j->setType(Job::JPG);
        break;
    case 2:
        j->setType(Job::TIFF);
        break;
    default:
        break;
    }
    emit jobGenerated(j);
    //qDebug() << "added job " << list_.size();
}

QString JobGeneratorFake::generateTitle() {
    QString characters =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    QString title = "";
    for (int i = 0; i < 10; ++i) {
        title.append(characters.at(rand() % (characters.size() - 1)));
    }

    return title;
}
