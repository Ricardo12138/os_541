#include "run.h"
#include "stdafx.h"
#include "Process.h"
#include "new.h"
#include "ready.h"
#include "running.h"
#include "global.h"
#include "waiting.h"
#include "terminated.h"
void run()
{
	thread newThread(new_detect);
	thread readyThread(ready, "FCFS");
	thread runningThread(running);
	thread waitingThread(waiting);
	thread terminatedThread(terminated);

	newThread.join();
	readyThread.join();
	runningThread.join();
	waitingThread.join();
	terminatedThread.join();
}



void hello1()
{
	while (true) {
		Sleep(2000);
		Process process;
		readyQueue.push_back(process);
	}

}

void hello2()
{
	while (true)
		cout << "hello2" << endl;
}

void run1()
{
	thread th1(hello1);
	//thread th2(hello2);

	th1.join();
	//th2.join();
}