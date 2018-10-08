#include "ready.h"
#include "stdafx.h"

void readyThread::readyFCFS()
{
	while (true)
	{
		if (!readyQueue.empty())
		{
			if (runningQueue.empty())
			{
				Process process = readyQueue.front();
				runningQueue.push_back(process);
				readyQueue.pop_front();
			}
		}
		//Sleep(TIME);
        msleep(10);
	}
}

void readyThread::readyPRIORITY()
{
	while (true)
	{
		//Sleep(TIME);
		if (!readyQueue.empty())
		{
			//prioritySort(readyQueue);	//�Ȱ������ȼ�����
			readyQueue.prioritySort1();
			if (runningQueue.empty())
			{
				Process process = readyQueue.front();
				runningQueue.push_back(process);
				readyQueue.pop_front();
			}
		}
        msleep(10);
	}
}
/*
void ready(string scheduleType)
{
	if (scheduleType == SA_FCFS)
		readyFCFS();
	else if (scheduleType == SA_PRIORITY)
		readyPRIORITY();
	else
		cout << "û�и����͵ĵ����㷨" << endl;
}
*/
void readyThread::run(){
    if (scheduleType == SA_FCFS)
        readyFCFS();
    else if (scheduleType == SA_PRIORITY)
        readyPRIORITY();
    else
        cout << "û�и����͵ĵ����㷨" << endl;
}
