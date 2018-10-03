#include "stdafx.h"
#include "PCB.h"
#include "Operation.h"
#include "global.h"

PCB::PCB()
{
	srand(time(0));
	this->processId = rand()%10000;	//10000以内的随机数作为进程ID
	this->processState = -1;		//默认进程状态为-1，表示未被成功new
	this->pc = 0;
	this->memoryAddress = 0;
	this->priority = 0;				//默认优先级为最低优先级0

	//默认使用job1作为默认任务
	for (int i = 0; i < job1.size(); i++) {
		string str = job1[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
}

PCB::PCB(const vector<string> job)
{
	srand(time(0));
	this->processId = rand() % 10000;	//10000以内的随机数作为进程ID
	this->processState = -1;		//默认进程状态为-1，表示未被成功new
	this->pc = 0;
	this->memoryAddress = 0;
	this->priority = 0;				//默认优先级为最低优先级0

	for(int i = 0; i < job.size(); i++) {
		string str = job[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
}

PCB& PCB::operator=(PCB& a)
{
	this->processId = a.getProcessId();
	this->processState = a.getProcessState();
	this->pc = a.getPc();
	this->memoryAddress = a.getMemoryAddress();
	this->priority = a.getPriority();
	this->jobs = a.jobs;
	return *this;
}

PCB::~PCB()
{
}

int PCB::getProcessId() {
	return processId;
}

void PCB::setProcessId(int id) {
	processId = id;
}

int PCB::getProcessState() {
	return processState;
}

void PCB::setProcessState(int state) {
	processState = state;
}

int PCB::getPc() {
	return pc;
}

void PCB::setPc(int pc) {
	this->pc = pc;
}

int PCB::getMemoryAddress() {
	return memoryAddress;
}

void PCB::setMemoryAddress(int address) {
	memoryAddress = address;
}

int PCB::getPriority() {
	return priority;
}

void PCB::setPriority(int priority) {
	this->priority = priority;
}

vector<Operation> PCB::getJobs()
{
	return jobs;
}

void PCB::setJobs(vector<Operation> jobs)
{
	this->jobs = jobs;
}