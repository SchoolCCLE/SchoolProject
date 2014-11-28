#include "JobList.h"
#include <QtQml>

JobList::JobList()
{
    qmlRegisterType<JobList>("JobMgr", 1, 0, "JobList");
}
