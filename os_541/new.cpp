#include "new.h"
#include "Process.h"
#include "stdafx.h"
#include "global.h"
//Ĭ��
void produce()
{
	Process process;
	PCB pcb;
	pcb.setPriority(2);
	process.setPCB(pcb);
	newQueue.push_back(process);
}

//����
void produce(int priority)
{
	Process process;
	PCB pcb;
	pcb.setPriority(priority);
	pcb.setProcessState(0);
	process.setPCB(pcb);
	newQueue.push_back(process);
}

void produce(vector<string> job)
{
	Process process;
	PCB pcb(job);
	//����pcb.setJob(job);
	pcb.setProcessState(0);
	process.setPCB(pcb);
	newQueue.push_back(process);
}