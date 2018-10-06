#include "waiting.h"
#include "stdafx.h"
#include "Process.h"
#include "PCB.h"
#include "global.h"
#include "Operation.h"
#include "running.h"

void waiting()
{
	while (true)
	{
		if (!waitingQueue.empty())
		{
			Process& process = waitingQueue.front();
			PCB pcb = process.getPCB();
			pair<int, int> nowJob = pcb.getNowJob();
			int id = nowJob.first;
			int lastTime = nowJob.second;
			Operation opt = pcb.getJobs()[id];
			if (opt.getType() == IT_K)//键盘输入
			{
				Sleep(lastTime * TIME);//模拟IO输入的时间
				cout << pcb.getProcessId() << " 键盘输入结束" << endl;
				nowJob.first = id + 1;
				nowJob.second = (pcb.getJobs())[id + 1].getTime();
				pcb.setNowJob(nowJob);
				process.setPCB(pcb);
				process.setFinishIOFlag(true);
				Process newProcess = process;
				readyQueue.push_back(newProcess);
				eraseQueueElem(waitingQueue, process);

			}
			else if (opt.getType() == IT_P)//打印机输出
			{
				
				Sleep(lastTime * TIME);//模拟IO输入的时间
				cout << pcb.getProcessId() << " 打印机输出结束" << endl;
				nowJob.first = id + 1;
				nowJob.second = (pcb.getJobs())[id + 1].getTime();
				pcb.setNowJob(nowJob);
				process.setPCB(pcb);
				process.setFinishIOFlag(true);
				Process newProcess = process;
				readyQueue.push_back(newProcess);
				eraseQueueElem(waitingQueue, process);
			}
			else
			{
				cout << "未知操作" << endl;
			}
		}
	}

}