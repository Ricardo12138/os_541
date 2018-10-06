#include "running.h"
#include "stdafx.h"
#include "global.h"

void eraseQueueElem(deque<Process>& dq, Process process)
{
	auto last = find(begin(dq), end(dq), process);
	while (last != end(dq))
	{
		dq.erase(last);
		last = find(begin(dq), end(dq), process);
	}
}

//false, false没结束，true, false中断，false,true IO，true,true结束
pair<bool, bool> runningJob(Process& process)
{
	PCB pcb = process.getPCB();
	pair<int, int> nowJob = pcb.getNowJob();

	int id = nowJob.first;
	int lastTime = nowJob.second;
	Operation opt = (pcb.getJobs())[id];
	pair<bool, bool> result;
	result.first = false;
	result.second = false;
	if (opt.getType() != IT_Q)
	{
		if (opt.getType() == IT_I)
		{
			cout << process.getPCB().getProcessId() << " 被中断 I" << endl;
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setInteruptedFlag(true);
			process.setPCB(pcb);
			result.first = true;//中断
			result.second = false;//没结束
		}
		else if (opt.getType() == IT_K)
		{
			cout << pcb.getProcessId() << " 键盘输入中" << endl;
			pcb.setNowJob(nowJob);
			process.setWaitIOFlag(true);
			process.setPCB(pcb);
			result.first = false; //IO
			result.second = true;
		}
		else if (opt.getType() == IT_P)
		{
			cout << pcb.getProcessId() << " 打印机输出中" << endl;
			pcb.setNowJob(nowJob);
			process.setWaitIOFlag(true);
			process.setPCB(pcb);
			result.first = false; //IO
			result.second = true;
		}
		else
		{
			if (opt.getType() == IT_W)
			{
				cout << process.getPCB().getProcessId() << " 写文件中 W" << endl;
				Sleep(lastTime * TIME);//把剩余的时间执行完
				result.first = false;//正常没结束
				result.second = false;
			}
			else if (opt.getType() == IT_R)
			{
				cout << process.getPCB().getProcessId() << " 读文件中 R" << endl;
				Sleep(lastTime * TIME);//把剩余的时间执行完
				result.first = false;//正常没结束
				result.second = false;
			}
			else if (opt.getType() == IT_C)
			{
				cout << process.getPCB().getProcessId() << " 计算中 C" << endl;
				Sleep(lastTime * TIME);//把剩余的时间执行完
				result.first = false;//正常没结束
				result.second = false;
			}
			else
			{
				cout << "running未知操作" << endl;
			}
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setPCB(pcb);
		}
	}
	else
	{
		result.first = true;
		result.second = true;
		cout << process.getPCB().getProcessId() << " 退出 Q" << endl;
		process.setIsLiveFlag(false);
	}
	return result;
}

void running()
{
	while (true)
	{
		if (!runningQueue.empty())
		{
			Process& process = runningQueue.front();
			//runningQueue.pop_front();

			pair<bool, bool> result = runningJob(process);//执行任务
			if (result.first && !result.second)//被中断
			{
				Process processNew = process;
				readyQueue.push_back(processNew); //加到就绪队列 
				eraseQueueElem(runningQueue, process);//从运行队列移除
			}
			if (!result.first && result.second)//IO
			{
				Process processNew = process;
				waitingQueue.push_back(processNew);//加入到等待队列
				eraseQueueElem(runningQueue, process);//从运行队列移除
			}
			if (result.first && result.second) //结束
			{
				Process processNew = process;
				terminatedQueue.push_back(process);
				eraseQueueElem(runningQueue, process);
				eraseQueueElem(readyQueue, process);
			}
		}
	}
}