#include "new.h"

/*创建时内存空间为0~160kb随机数
**优先级为0~5的随机数
**0为优先级最低，5为优先级最高
**若未安排工作，默认工作为job1
*/


//默认,工作为job1
void produce()
{
	Process process;
	PCB pcb;
	//内存默认范围为0~160kb
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

//其他
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
	//或者pcb.setJob(job);
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