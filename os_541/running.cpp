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

//false, falseû������true, false�жϣ�false,true IO��true,true����
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
			cout << process.getPCB().getProcessId() << " ���ж� I" << endl;
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
			cout << pcb.getProcessId() << " ����������" << endl;
			pcb.setNowJob(nowJob);
			process.setWaitIOFlag(true);
			process.setPCB(pcb);
			result.first = false; //IO
			result.second = true;
		}
		else if (opt.getType() == IT_P)
		{
			cout << pcb.getProcessId() << " ��ӡ�������" << endl;
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
				cout << process.getPCB().getProcessId() << " д�ļ��� W" << endl;
				Sleep(lastTime * TIME);//��ʣ���ʱ��ִ����
				result.first = false;//����û����
				result.second = false;
			}
			else if (opt.getType() == IT_R)
			{
				cout << process.getPCB().getProcessId() << " ���ļ��� R" << endl;
				Sleep(lastTime * TIME);//��ʣ���ʱ��ִ����
				result.first = false;//����û����
				result.second = false;
			}
			else if (opt.getType() == IT_C)
			{
				cout << process.getPCB().getProcessId() << " ������ C" << endl;
				Sleep(lastTime * TIME);//��ʣ���ʱ��ִ����
				result.first = false;//����û����
				result.second = false;
			}
			else
			{
				cout << "runningδ֪����" << endl;
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
		cout << process.getPCB().getProcessId() << " �˳� Q" << endl;
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

			pair<bool, bool> result = runningJob(process);//ִ������
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
				Process processNew = process;
				terminatedQueue.push_back(process);
				eraseQueueElem(runningQueue, process);
				eraseQueueElem(readyQueue, process);
			}
		}
	}
}