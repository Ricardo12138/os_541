#include "stdafx.h"
#include "Process.h"

Process::Process()
{
	PCB newPcb;
	this->pcb = newPcb;
	this->interuptedFlag = false;
	this->waitIOFlag = false;
	this->finishIOFlag = false;
	this->isLiveFlag = true;
}

Process::Process(vector<string> job)
{
	PCB newPcb(job);
	this->pcb = newPcb;
	this->interuptedFlag = false;
	this->waitIOFlag = false;
	this->finishIOFlag = false;
	this->isLiveFlag = true;
}

Process::Process(const Process& a)
{
	this->pcb = a.pcb;
	this->interuptedFlag = a.interuptedFlag;
	this->waitIOFlag = a.waitIOFlag;
	this->finishIOFlag = a.finishIOFlag;
	this->isLiveFlag = a.isLiveFlag;
}

Process& Process::operator=(const Process& a)
{
	this->pcb = a.pcb;
	this->interuptedFlag = a.interuptedFlag;
	this->waitIOFlag = a.waitIOFlag;
	this->finishIOFlag = a.finishIOFlag;
	this->isLiveFlag = a.isLiveFlag;
	return *this;
}

bool Process::operator==(const Process& a)
{
	
	if (a.pcb.getProcessId() == pcb.getProcessId())
		return true;
	return false;
}

Process::~Process()
{
}

PCB Process::getPCB () const
{
	return pcb;
}

void Process::setPCB(PCB pcb) {
	this->pcb = pcb;
}

bool Process::getInteruptedFlag()  const
{
	return interuptedFlag;
}

void Process::setInteruptedFlag(bool flag) 
{
	interuptedFlag = flag;
}

bool Process::getWaitIOFlag()  const 
{
	return waitIOFlag;
}

void Process::setWaitIOFlag(bool flag) 
{
	waitIOFlag = flag;
}

bool Process::getFinishIOFlag()  const 
{
	return finishIOFlag;
}

void Process::setFinishIOFlag(bool flag) 
{
	finishIOFlag = flag;
}

bool Process::getIsLiveFlag() const
{
	return isLiveFlag;
}

void Process::setIsLiveFlag(bool flag)
{
	isLiveFlag = flag;
}

void Process::show()
{
	cout << "interuptedFlag: " << this->interuptedFlag << endl
		<< "waitIOFlag: " << this->waitIOFlag << endl
		<< "finishIOFinish: " << this->finishIOFlag << endl;
	this->pcb.show();
}