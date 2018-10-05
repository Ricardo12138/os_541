#include "waiting.h"
#include "stdafx.h"
#include "Process.h"
#include "PCB.h"
#include "global.h"
#include "Operation.h"

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
				Sleep(lastTime);//模拟IO输入的时间
				Process newProcess = process;
				readyQueue.push_back(newProcess);
				
			}
			else if (opt.getType() == IT_P)//打印机输出
			{

			}
			else
			{
				cout << "未知操作" << endl;
			}
		}
	}
	
}