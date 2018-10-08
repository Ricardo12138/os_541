#pragma once
#include <QThread>
#include"stdafx.h"
#include"global.h"
#include"memory.h"
void terminated();
class terminatedThread:public QThread
{
    Q_OBJECT
public:
    void run();
};
