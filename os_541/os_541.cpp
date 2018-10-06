// os_541.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Process.h"
#include "pcb.h"
#include "scheduleAlgorithm.h"
#include "global.h"
#include "Operation.h"
#include "running.h"
#include "run.h"
#include<iostream>
#include<vector>
#include"file_mangement.h"

using namespace std;

//vector<string> job1 = { "M 4", "Y 2", "C 10", "I", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q" };
int main()
{
	/*PCB pcb1(job1);
	pcb1.setPriority(0);

	PCB pcb2;
	pcb2.setPriority(1);
	pcb2.setJobs(job2);

	//PCB pcb3;
	//pcb3.setPriority(2);

	Process process1;
	process1.setPCB(pcb1);
	
	Process process2;
	process2.setPCB(pcb2);
	
	//Process process3;
	//process3.setPCB(pcb3);
	
	//Process process4;
	//process4 = process2;
	
	readyQueue.push_back(process1);
	readyQueue.push_back(process2);

	cout << "***" << readyQueue.size() << endl;
	cout << "|||" << terminatedQueue.size() << endl;
	
	//run1();
	run();//启动线程

	while (!terminatedQueue.empty())
	{
		Process p = terminatedQueue.front();
		terminatedQueue.pop_front();
		p.show();
	}

	//cout << process1.getPCB().getProcessId() << endl;
	//cout << process2.getPCB().getProcessId() << endl;
	//cout << process3.getPCB().getProcessId() << endl;
	//cout << process4.getPCB().getProcessId() << endl;
	//cout << runningQueue.size() << endl;
	//eraseQueueElem(runningQueue, process2);
	//cout << runningQueue.size() << endl;


	return 0;
	*/
	//薛顺国的main
	
	//node root;
	node *tempnode = new node;
	int choose = 0;

	Root = Create();
	cout << Root.getName() << endl;
	tempnode = &Root;
	while (true) {
		cout << "当前目录下创建：1；当前目录的兄弟：2；遍历：3" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			Add(*tempnode);
			tempnode = (*tempnode).getChild();
			cout << tempnode->getName() << endl;
			break;
		case 2:
			*tempnode = *tempnode->getParent();
			Add(*tempnode);
			tempnode = (*tempnode).getChild();
			cout << tempnode->getName() << endl;
			break;
		case 3:
			//bool i = false;
			cout << "找到？" << Search(Root, "ro") << endl;
			T = 0;
			break;
		default:;
		}
	//Add(*tempnode);
	//tempnode = (*tempnode).getChild();
	//cout << tempnode->getName() << endl;
	}

	getchar();
	return 0;
	
}

