#include "printerengine.h"

PrinterEngine::PrinterEngine(QObject *parent) :
    QObject(parent)
{
    m_stateNumber=1;
    m_printerType = 1;
    if (m_printerType == 0){
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
    }
    if (m_printerType == 1){
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
        m_cartridges.append(new Cartridge("Cyan",30,200));
        m_cartridges.append(new Cartridge("Magenta",30,200));
        m_cartridges.append(new Cartridge("Yellow",30,200));
        m_cartridges.append(new Cartridge("Black",30,200));
    }

}

void PrinterEngine::startJobs()
{
    Job* job1 = new Job(NULL);
    job1->setJobId(1234);
    job1->changeTipe(2);
    job1->setName("Fichero 1");
    job1->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job1->setState("printing");
    job1->setCyan(Job::generateRandomNumber(1000, 100));
    job1->setMagenta(Job::generateRandomNumber(1000, 100));
    job1->setYellow(Job::generateRandomNumber(1000, 100));
    job1->setBlack(Job::generateRandomNumber(1000, 100));

    Job* job2 = new Job();
    job2->setJobId(2345);
    job2->setTipe(2);
    job2->setName("Fichero 2");
    job2->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job2->setState("printed");
    job2->setCyan(Job::generateRandomNumber(1000, 100));
    job2->setMagenta(Job::generateRandomNumber(1000, 100));
    job2->setYellow(Job::generateRandomNumber(1000, 100));
    job2->setBlack(Job::generateRandomNumber(1000, 100));

    Job* job3 = new Job();
    job3->setJobId(3456);
    job3->setTipe(1);
    job3->setName("Fichero 3");
    job3->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job3->setState("waitting to print");
    job3->setCyan(Job::generateRandomNumber(1000, 100));
    job3->setMagenta(Job::generateRandomNumber(1000, 100));
    job3->setYellow(Job::generateRandomNumber(1000, 100));
    job3->setBlack(Job::generateRandomNumber(1000, 100));

    Job* job4 = new Job();
    job4->setJobId(4567);
    job4->setTipe(1);
    job4->setName("Fichero 4");
    job4->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job4->setState("printed");
    job4->setCyan(Job::generateRandomNumber(1000, 100));
    job4->setMagenta(Job::generateRandomNumber(1000, 100));
    job4->setYellow(Job::generateRandomNumber(1000, 100));
    job4->setBlack(Job::generateRandomNumber(1000, 100));

    Job* job5 = new Job();
    job5->setJobId(5678);
    job5->setTipe(0);
    job5->setName("Fichero 5");
    job5->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job5->setState("printed");
    job5->setCyan(Job::generateRandomNumber(1000, 100));
    job5->setMagenta(Job::generateRandomNumber(1000, 100));
    job5->setYellow(Job::generateRandomNumber(1000, 100));
    job5->setBlack(Job::generateRandomNumber(1000, 100));

    Job* job6 = new Job();
    job6->setJobId(6789);
    job6->setTipe(3);
    job6->setName("Fichero 6");
    job6->setPrintingTime(Job::generateRandomNumber(180 ,15));
    job6->setState("waitting to print");
    job6->setCyan(Job::generateRandomNumber(1000, 100));
    job6->setMagenta(Job::generateRandomNumber(1000, 100));
    job6->setYellow(Job::generateRandomNumber(1000, 100));
    job6->setBlack(Job::generateRandomNumber(1000, 100));

    m_jobs.append(job1);
    m_jobs.append(job2);
    m_jobs.append(job3);
    m_jobs.append(job4);
    m_jobs.append(job5);
    m_jobs.append(job6);
}

void PrinterEngine::changeState(int state)
{
    if (state ==1){
        m_stateNumber = 1;
        //m_stateText = "Idle";
    }
    if (state ==3){
        m_stateNumber = 3;
        //m_stateText = "Warning";
    }
    if (state ==4){
        m_stateNumber = 4;
        //m_stateText = "Error";
    }

}
