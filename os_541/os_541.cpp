// os_541.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Process.h"
#include "pcb.h"
#include "scheduleAlgorithm.h"
#include "global.h"
#include "Operation.h"
#include "running.h"
#include "run.h"
#include<iostream>
#include<vector>
#include"file_mangement.h"
#include "new.h"
#include "memory.h"
#include "ProducerConsumer.h"
using namespace std;

int main()
{
	Root = Create(); //初始化文件根

	initialization();//初始化内存

	//产生进程
	produce(job1);
	produce(job2);
	produce(job3);
	produce(job4);
	produce(job5);

	startProducerConsumer();//启动生产者消费者线程

	run();//启动进程调度的5个线程

	return 0;
	
}

