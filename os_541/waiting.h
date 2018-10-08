#pragma once
#include "stdafx.h"
#include "Process.h"
#include "PCB.h"
#include "global.h"
#include "Operation.h"
#include "running.h"
#include <QThread>
void waiting();

class waitingThread:public QThread
{
    Q_OBJECT
public:
    void run();
};
