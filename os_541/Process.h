#pragma once

#include "PCB.h"
class Process
{
private:
	PCB pcb;				//PCB
	bool interuptedFlag;	//中断标志
	bool waitIOFlag;		//等待IO标志
	bool finishIOFlag;		//IO结束标志
	bool isLiveFlag;		//是否存活标志
public:
	Process();
	Process(vector<string> job);
	Process(const Process& a);
	Process& operator=(const Process& a);
	bool operator==(const Process& a);
	~Process();

	PCB getPCB() const;
	void setPCB(PCB pcb);

	bool getInteruptedFlag() const;
	void setInteruptedFlag(bool flag);

	bool getWaitIOFlag() const;
	void setWaitIOFlag(bool flag);

	bool getFinishIOFlag() const;
	void setFinishIOFlag(bool flag);

	bool getIsLiveFlag() const;
	void setIsLiveFlag(bool flag);

	void show();
};

