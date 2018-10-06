#include "running.h"
#include "stdafx.h"
#include "global.h"

//**
void eraseQueueElem(deque<Process>& dq, Process process)
{
	auto last = find(begin(dq), end(dq), process);
	while (last != end(dq))
	{
		dq.erase(last);
		last = find(begin(dq), end(dq), process);
	}
}

//false, falseû������true, false�жϣ�false,true IO��true,true����
pair<bool, bool> runningFCFS(Process& process)
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
		if (opt.getType() == IT_Y)
		{	
			cout << "FCFS��" << process.getPCB().getProcessId() << " д���ȼ��� Y" << endl;
			pcb.setPriority(opt.getPriorityNumber());
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setPCB(pcb);
			result.first = false;//����û����
			result.second = false;
		}
		else if (opt.getType() == IT_M)
		{
			cout << "FCFS��" << process.getPCB().getProcessId() << " д�ڴ� M" << endl;
			pcb.setMemorySpace(opt.getBlock());
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			cout << pcb.getNowJob().first << ",,," << pcb.getNowJob().second << endl;
			process.setPCB(pcb);
			result.first = false;//����û����
			result.second = false;
		}
		else if (opt.getType() == IT_I)
		{
			cout << "FCFS��" << process.getPCB().getProcessId() << " ���ж� I" << endl;
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setInteruptedFlag(true);
			process.setPCB(pcb);
			result.first = true;//�ж�
			result.second = false;//û����
		}
		else if (opt.getType() == IT_K)
		{
			cout << "FCFS��" << process.getPCB().getProcessId() << " ���������� K" << endl;
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setWaitIOFlag(true);
			process.setPCB(pcb);
			result.first = false; //IO
			result.second = true;
		}
		else if (opt.getType() == IT_P)
		{
			cout << "FCFS��" << process.getPCB().getProcessId() << " ��������� P" << endl;
			nowJob.first = id + 1;
			nowJob.second = (pcb.getJobs())[id + 1].getTime();
			pcb.setNowJob(nowJob);
			process.setWaitIOFlag(true);
			process.setPCB(pcb);
			result.first = false; //IO
			result.second = true;
		}
		else
		{
			Sleep(lastTime);//��ʣ���ʱ��ִ����
			if (opt.getType() == IT_W)
			{
				cout << "FCFS��" << process.getPCB().getProcessId() << " д�ļ��� W" << endl;
				result.first = false;//����û����
				result.second = false;
			}
			else if (opt.getType() == IT_R)
			{
				cout << "FCFS��" << process.getPCB().getProcessId() << " ���ļ��� R" << endl;
				result.first = false;//����û����
				result.second = false;
			}
			else if (opt.getType() == IT_C)
			{
				cout << "FCFS��" << process.getPCB().getProcessId() << " ������ C" << endl;
				result.first = false;//����û����
				result.second = false;
			}
			else
			{
				cout << "FCFSδ֪����" << endl;
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
		cout << "FCFS��" << process.getPCB().getProcessId() << " �˳� Q" << endl;
		process.setIsLiveFlag(false);
	}
	return result;
}

void runningPRIORITY()
{

}

void runningRR()
{

}

void running(string scheduleType)
{
	while (true)
	{
		if (!runningQueue.empty())
		{
			Process& process = runningQueue.front();
			//runningQueue.pop_front();
			if (scheduleType == SA_FCFS) {
				pair<bool, bool> result = runningFCFS(process);
				
				if (result.first && !result.second)//���ж�
				{
					Process processNew = process;
					readyQueue.push_back(processNew); //�ӵ���������
					eraseQueueElem(runningQueue, process);//�����ж����Ƴ�
				}
				if (!result.first && result.second)//IO
				{
					Process processNew = process;
					waitingQueue.push_back(processNew);//���뵽�ȴ�����
					eraseQueueElem(runningQueue, process);//�����ж����Ƴ�
				}
				if (result.first && result.second) //����
				{
					eraseQueueElem(runningQueue, process);
					eraseQueueElem(readyQueue, process);
					terminatedQueue.push_back(process);
				}	
			}

		}
	}
}