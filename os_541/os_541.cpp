// os_541.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Process.h"
#include "pcb.h"
#include "scheduleAlgorithm.h"
#include "global.h"
#include "Operation.h"

int main()
{
	PCB pcb1(job1);
	pcb1.setPriority(0);

	PCB pcb2;
	pcb2.setPriority(1);

	PCB pcb3;
	pcb3.setPriority(2);

	Process process1;
	process1.setPCB(pcb1);

	Process process2;
	process2.setPCB(pcb2);

	Process process3;
	process3.setPCB(pcb3);

	Process process4;
	process4 = process2;

	vector<Operation> jobs = pcb1.getJobs();
	for (int i = 0; i < jobs.size(); i++)
	{
		Operation a = jobs[i];
		cout << a.getType() << "," << a.getTime() << "," << a.getFileName() << "," << a.getFileSize() << endl;
	}
	//processQueue.push_back(process1);
	//processQueue.push_back(process2);
	//processQueue.push_back(process3);
	//processQueue.push_back(process4);

	//prioritySort(processQueue);
	//for (int i = 0; i < processQueue.size(); i++)
	//{
	//	PCB pcb = processQueue[i].getPCB();
	//	cout << pcb.getPriority() << " ";
	//}
	//cout << endl;
	return 0;
}

