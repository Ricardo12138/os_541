#pragma once

#include "PCB.h"
class Process
{
private:
	PCB pcb;
	bool interuptedFlag;
	bool waitIOFlag;
	bool finishIOFlag;
public:
	Process();
	Process(vector<string> job);
	Process& operator=(Process& a);
	~Process();

	PCB getPCB();
	void setPCB(PCB pcb);

	int getInteruptedFlag();
	void setInteruptedFlag(int flag);

	int getWaitIOFlag();
	void setWaitIOFlag(int flag);

	int getFinishIOFlag();
	void setFinishIOFlag(int flag);
};

