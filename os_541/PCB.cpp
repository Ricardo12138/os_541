#include "stdafx.h"
#include "PCB.h"
#include "Operation.h"
#include "global.h"

PCB::PCB()
{
	vector<string> JOB1 = {"C 10", "I", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q" };
	srand(seed++);
	this->processId = rand()%10000;	//10000以内的随机数作为进程ID
	this->processState = -1;		//默认进程状态为-1，表示未被成功new
	this->pc = 0;					
	this->memorySpace = 0;			
	this->start_addr = -1;
	this->priority = 0;				//默认优先级为最低优先级0

	//默认使用job1作为默认任务
	for (int i = 0; i < JOB1.size(); i++) {
		string str = JOB1[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
	pair<int, int> nowjob;
	nowjob.first = 0;
	nowjob.second = jobs[0].getTime();
	this->nowJob.first = nowjob.first;
	this->nowJob.second = nowjob.second;
}

PCB::PCB(const vector<string> job)
{
	srand(seed++);
	this->processId = rand() % 10000;	//10000以内的随机数作为进程ID
	this->processState = -1;		//默认进程状态为-1，表示未被成功new
	this->pc = 0;
	this->memorySpace = 0;
	this->start_addr = -1;
	this->priority = 0;				//默认优先级为最低优先级0
	
	this->jobs.clear();//清空jobs
	for(int i = 0; i < job.size(); i++) {
		string str = job[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}

	pair<int, int> nowjob;
	nowjob.first = 0;
	nowjob.second = jobs[0].getTime();
	this->nowJob.first = nowjob.first;
	this->nowJob.second = nowjob.second;
}

PCB& PCB::operator=(const PCB& a)
{
	this->processId = a.processId;
	this->processState = a.processState;
	this->pc = a.pc;
	this->memorySpace = a.memorySpace;
	this->start_addr = a.start_addr;
	this->priority = a.priority;
	this->jobs = a.jobs;
	this->nowJob.first = a.nowJob.first;
	this->nowJob.second = a.nowJob.second;
	return *this;
}

PCB::PCB(const PCB& a)
{
	this->processId = a.processId;
	this->processState = a.processState;
	this->pc = a.pc;
	this->memorySpace = a.memorySpace;
	this->start_addr = a.start_addr;
	this->priority = a.priority;
	this->jobs = a.jobs;
	this->nowJob.first = a.nowJob.first;
	this->nowJob.second = a.nowJob.second;
}
PCB::~PCB()
{
}

int PCB::getProcessId() const{
	return processId;
}

void PCB::setProcessId(int id) {
	processId = id;
}

int PCB::getProcessState() const{
	return processState;
}

void PCB::setProcessState(int state) {
	processState = state;
}

int PCB::getPc() const{
	return pc;
}

void PCB::setPc(int pc) {
	this->pc = pc;
}

int PCB::getaddr() const {
	return start_addr;
}

void PCB::setaddr(int addr) {
	this->start_addr = addr;
}

int PCB::getMemorySpace() const{
	return memorySpace;
}

void PCB::setMemorySpace(int space) {
	memorySpace = space;
}

int PCB::getPriority() const{
	return priority;
}

void PCB::setPriority(int priority) {
	this->priority = priority;
}

vector<Operation> PCB::getJobs() const
{
	return jobs;
}

void PCB::setJobs(vector<string> jobs)
{
	this->jobs.clear();//清空jobs

	for (int i = 0; i < jobs.size(); i++) {
		string str = jobs[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
	this->nowJob.first = 0;
	this->nowJob.second = this->jobs[0].getTime();
}

pair<int, int> PCB::getNowJob() const
{
	return nowJob;
}

void PCB::setNowJob(pair<int, int> job)
{
	nowJob.first = job.first;
	nowJob.second = job.second;
}

void PCB::show()
{
	//输出基本信息
	cout << "processId: " << this->processId << endl
		<< "processState: " << this->processState << endl
		<< "pc: " + this->pc << endl
		<< "memorySpace: " << this->memorySpace << endl
		<< "start address: " << this->start_addr << endl
		<< "priority: " << this->priority << endl;
	//输出job
	for (int i = 0; i < jobs.size(); i++)
	{
		Operation a = jobs[i];
		cout << a.getType() << "," << a.getTime() << "," << a.getFileName() << "," << a.getFileSize() << endl;
	}
	cout << "nowJobId: " << this->nowJob.first << "," << "lastTime: " << this->nowJob.second << endl;
}