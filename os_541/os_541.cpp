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
#include "new.h"
#include "memory.h"
using namespace std;

int main()
{
	
	/*
	//薛顺国的main
	
	node root;
	node *tempnode = new node;
	int choose = 0;

	Root = Create();
	cout << Root.getName() << endl;
	tempnode = &Root;
	while (true) {
		cout << "当前目录下创建：1；当前目录的兄弟：2；遍历：3;删除：4;写文件：5" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			Add(*tempnode);
			tempnode = (*tempnode).getChild();
			cout << tempnode->getName() << endl;
			break;
		case 2:
			tempnode = (*tempnode).getParent();
			Add(*tempnode);
			tempnode = (*tempnode).getChild();
			cout << tempnode->getName() << endl;
			break;
		case 3:
			//bool i = false;
			cout << "找到？" << Search(Root, "aaa") << endl;
			T = 0;
			break;
		case 4:
			fileDelete(*Root.getChild());
			break;
		case 5 :
			fileWrite("gg", 5, 5);
			break;
		default:;
		}
	//Add(*tempnode);
	//tempnode = (*tempnode).getChild();
	//cout << tempnode->getName() << endl;
	}

	getchar();
	*/
	/**
	 *cyw main
	 */
	/*PCB pcb1(job1);
	pcb1.setPriority(0);
	PCB pcb2;
	pcb2.setPriority(3);
	pcb2.setJobs(job2);

	PCB pcb3(job3);
	pcb3.setPriority(3);

	PCB pcb4(job4);
	pcb4.setPriority(2);

	PCB pcb5(job5);
	pcb5.setPriority(4);

	Process process1;
	process1.setPCB(pcb1);

	Process process2;
	process2.setPCB(pcb2);


	Process process3;
	process3.setPCB(pcb3);

	Process process4;
	process4.setPCB(pcb4);

	Process process5;
	process5.setPCB(pcb5);

	readyQueue.push_back(process1);
	readyQueue.push_back(process2);
	readyQueue.push_back(process3);
	readyQueue.push_back(process4);
	readyQueue.push_back(process5);*/
	Root = Create(); 
	initialization();
	produce(job1);
	produce(job2);
	produce(job3);
	produce(job4);
	produce(job5);
	
	run();
	
	//run1();
	/*run();//启动线程 

	while (!terminatedQueue.empty())
	{
		Process p = terminatedQueue.front();
		terminatedQueue.pop_front();
		p.show();
	}*/
	return 0;
	
}

