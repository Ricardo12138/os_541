#pragma once
#include "Operation.h"

class PCB
{
private:
	int processId;		//进程id
	int processState;	//进程当前状态
	int pc;				//程序计数器
	int memorySpace;	//内存空间
	int priority; //进程优先级
	vector<Operation> jobs;	//对应任务
	pair<int, int> nowJob; //正在执行的任务或刚开始的任务，1：第几个，2：剩的时间

public:
	PCB();
	PCB(const vector<string> job);
	PCB(const PCB& a);
	PCB& operator=(const PCB& a);
	~PCB();

	int getProcessId() const;
	void setProcessId(int id);

	int getProcessState() const;
	void setProcessState(int state);

	int getPc() const;
	void setPc(int pc);

	int getMemorySpace() const;
	void setMemorySpace(int space);

	int getPriority() const;
	void setPriority(int priority);

	vector<Operation> getJobs() const;
	void setJobs(vector<string> jobs);

	pair<int, int> getNowJob() const;
	void setNowJob(pair<int, int> job);

	void show();
};

