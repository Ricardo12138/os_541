#include "run.h"
#include "stdafx.h"
#include "Process.h"
#include "ready.h"
#include "running.h"
#include "global.h"

void run()
{
	thread readyToRunningThread(readyToRunning, "FCFS");
	thread runningToReadyThread(running, "FCFS");
	

	runningToReadyThread.join();
	runningToReadyThread.join();
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