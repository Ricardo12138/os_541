#include "stdafx.h"
#include "Process.h"

Process::Process()
{
	PCB newPcb;
	this->pcb = newPcb;
	this->interuptedFlag = false;
	this->waitIOFlag = false;
	this->finishIOFlag = false;
}

Process::Process(vector<string> job)
{
	PCB newPcb(job);
	this->pcb = newPcb;
	this->interuptedFlag = false;
	this->waitIOFlag = false;
	this->finishIOFlag = false;
}

Process& Process::operator=(Process& a)
{
	this->pcb = a.getPCB();
	this->interuptedFlag = a.getInteruptedFlag();
	this->waitIOFlag = a.getWaitIOFlag();
	this->finishIOFlag = a.getFinishIOFlag();
	return *this;
}

Process::~Process()
{
}

PCB Process::getPCB() {
	return pcb;
}

void Process::setPCB(PCB pcb) {
	this->pcb = pcb;
}

int Process::getInteruptedFlag() {
	return interuptedFlag;
}

void Process::setInteruptedFlag(int flag) {
	interuptedFlag = flag;
}

int Process::getWaitIOFlag() {
	return waitIOFlag;
}

void Process::setWaitIOFlag(int flag) {
	waitIOFlag = flag;
}

int Process::getFinishIOFlag() {
	return finishIOFlag;
}

void Process::setFinishIOFlag(int flag) {
	finishIOFlag = flag;
}