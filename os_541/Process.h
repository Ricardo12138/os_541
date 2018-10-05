#pragma once

#include "PCB.h"
class Process
{
private:
	PCB pcb;				//PCB
	bool interuptedFlag;	//�жϱ�־
	bool waitIOFlag;		//�ȴ�IO��־
	bool finishIOFlag;		//IO������־
	bool isLiveFlag;		//�Ƿ����־
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

