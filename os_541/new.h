#pragma once
#include "stdafx.h"
#include"Process.h"
#include"global.h"
#include"memory.h"
#include <QThread>
void produce();
void produce(int priority);
void produce(vector<string> job);
void new_detect();
class new_detect_thread:public QThread
{
    Q_OBJECT
public:
    void run();
};
