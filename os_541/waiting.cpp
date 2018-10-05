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
			if (opt.getType() == IT_K)//��������
			{
				Sleep(lastTime);//ģ��IO�����ʱ��
				Process newProcess = process;
				readyQueue.push_back(newProcess);
				
			}
			else if (opt.getType() == IT_P)//��ӡ�����
			{

			}
			else
			{
				cout << "δ֪����" << endl;
			}
		}
	}
	
}