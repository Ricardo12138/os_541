#pragma once
#include "stdafx.h"
#include "Process.h"
#include "global.h"
#include <QThread>
void eraseQueueElem(deque<Process>& dq, Process process);

void running();
pair<bool, bool> runningJob(Process& process);

class runningThread:public QThread
{
    Q_OBJECT
public:
    void run();
};
