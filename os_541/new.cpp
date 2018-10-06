#include "new.h"

/*����ʱ�ڴ�ռ�Ϊ0~160kb�����
**���ȼ�Ϊ0~5�������
**0Ϊ���ȼ���ͣ�5Ϊ���ȼ����
**��δ���Ź�����Ĭ�Ϲ���Ϊjob1
*/


//Ĭ��,����Ϊjob1
void produce()
{
	Process process;
	PCB pcb;
	//�ڴ�Ĭ�Ϸ�ΧΪ0~160kb
	int memory_space = rand() % 160;
	int start_addr;
	srand(seed++);
	pcb.setPriority(rand() % 6);
	pcb.setMemorySpace(memory_space);
	if (!newQueue.empty())
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
		return; 
	}
	start_addr = allocation(memory_space);
	if (start_addr == -1)
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
	}
	else
	{
		pcb.setProcessState(1);
		pcb.setaddr(start_addr);
		process.setPCB(pcb);
		readyQueue.push_back(process);
	}
}

//����
void produce(int priority)
{
	Process process;
	PCB pcb;
	int memory_space = rand() % 160;
	int start_addr;
	srand(seed++);
	pcb.setPriority(priority);
	pcb.setMemorySpace(memory_space);
	if (!newQueue.empty())
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
		return;
	}
	start_addr = allocation(memory_space);
	if (start_addr == -1)
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
	}
	else
	{
		pcb.setProcessState(1);
		pcb.setaddr(start_addr);
		process.setPCB(pcb);
		readyQueue.push_back(process);
	}
}

void produce(vector<string> job)
{
	Process process;
	PCB pcb(job);
	//����pcb.setJob(job);
	int memory_space = rand() % 160;
	int start_addr;
	srand(seed++);
	pcb.setPriority(rand() % 6);
	pcb.setMemorySpace(memory_space);
	if (!newQueue.empty())
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
		return;
	}
	start_addr = allocation(memory_space);
	if (start_addr == -1)
	{
		pcb.setProcessState(0);
		process.setPCB(pcb);
		newQueue.push_back(process);
	}
	else
	{
		pcb.setProcessState(1);
		pcb.setaddr(start_addr);
		process.setPCB(pcb);
		readyQueue.push_back(process);
	}
}


void new_detect()
{
	while (1)
	{
		if (!newQueue.empty())
		{
			int memory,start_addr;
			Process pro = newQueue.front;
			PCB pcb = pro.getPCB();
			memory = pcb.getMemorySpace();
			start_addr = allocation(memory);
			if (start_addr == -1)
			{
				newQueue.push_back(pro);
				newQueue.pop_front();
			}
			else
			{
				pcb.setaddr = start_addr;
				pcb.setProcessState = 1;
				pro.setPCB(pcb);
				readyQueue.push_back(pro);
				newQueue.pop_front();
			}

		}
	}
}