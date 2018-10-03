#pragma once
#include "Operation.h"
class PCB
{
private:
	int processId;		//进程id
	int processState;	//进程当前状态
	int pc;				//程序计数器
	int memoryAddress;	//内存地址
	int priority; //进程优先级
	vector<Operation> jobs;	//对应任务

public:
	PCB();
	PCB(const vector<string> job);
	PCB& operator=(PCB& a);
	~PCB();

	int getProcessId();
	void setProcessId(int id);

	int getProcessState();
	void setProcessState(int state);

	int getPc();
	void setPc(int pc);

	int getMemoryAddress();
	void setMemoryAddress(int address);

	int getPriority();
	void setPriority(int priority);

	vector<Operation> getJobs();
	void setJobs(vector<Operation> jobs);
};

