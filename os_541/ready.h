#pragma once
#include "stdafx.h"
#include "global.h"
#include "scheduleAlgorithm.h"
#include <QThread>
//void readyFCFS();

//void readyPRIORITY();

//void ready(string scheduleType);

class readyThread:public QThread
{
    Q_OBJECT
public:
    explicit readyThread(string s,QObject *p=NULL):scheduleType(s),QThread(p)
    {}
    void run();
    void readyFCFS();
    void readyPRIORITY();
    string scheduleType;
};
