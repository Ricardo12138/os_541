#include "ready.h"
#include "stdafx.h"
#include "global.h"
#include "scheduleAlgorithm.h"

void readyFCFS()
{
	while (true)
	{
		if (!readyQueue.empty())
		{
			Process process = readyQueue.front();
			runningQueue.push_back(process);
			readyQueue.pop_front();
		}
		Sleep(TIME);
	}
}

void readyPRIORITY()
{
	while (true)
	{
		Sleep(TIME);
		if (!readyQueue.empty())
		{
			prioritySort(readyQueue);	//先按照优先级排序
			Process process = readyQueue.front();
			runningQueue.push_back(process);
			readyQueue.pop_front();
		}
	}
}

void readyRR()
{
	bool again = false;
	while (true)
	{
		if (!again)
			Sleep(TIME);
		if (!readyQueue.empty())
		{
			Process process = readyQueue.front();
			if (!process.getIsLiveFlag())
			{
				readyQueue.pop_front();
				again = true;
				continue;
			}
			runningQueue.push_back(process);
		}
		again = false;
	}
}

void readyToRunning(string scheduleType)
{
	if (scheduleType == SA_FCFS)
		readyFCFS();
	else if (scheduleType == SA_PRIORITY)
		readyPRIORITY();
	else if (scheduleType == SA_RR)
		readyRR();
	else
		cout << "没有该类型的调度算法" << endl;
}