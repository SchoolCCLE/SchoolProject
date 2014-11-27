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

    startJobs();
}

void PrinterEngine::startJobs()
{
    Job* job1 = new Job();
    job1->changeJobId(1234);
    job1->changeType(2);
    job1->changeName("Fichero 1");
    job1->changeState("printing");

    Job* job2 = new Job();
    job2->changeJobId(2345);
    job2->changeType(2);
    job2->changeName("Fichero 2");
    job2->changeState("printed");

    Job* job3 = new Job();
    job3->changeJobId(3456);
    job3->changeType(1);
    job3->changeName("Fichero 3");
    job3->changeState("waitting to print");

    Job* job4 = new Job();
    job4->changeJobId(4567);
    job4->changeType(1);
    job4->changeName("Fichero 4");
    job4->changeState("printed");

    Job* job5 = new Job();
    job5->changeJobId(5678);
    job5->changeType(0);
    job5->changeName("Fichero 5");
    job5->changeState("printed");

    Job* job6 = new Job();
    job6->changeJobId(6789);
    job6->changeType(3);
    job6->changeName("Fichero 6");
    job6->changeState("waitting to print");

    m_jobs.append(job1);
    m_jobs.append(job3);
    m_jobs.append(job5);
    m_jobs.append(job6);

    m_jobsPrinted.append(job2);
    m_jobsPrinted.append(job4);
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
