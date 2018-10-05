#include "stdafx.h"
#include "PCB.h"
#include "Operation.h"
#include "global.h"

PCB::PCB()
{
	vector<string> JOB1 = { "M 4", "Y 2", "C 10", "I", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q" };
	srand(seed++);
	this->processId = rand()%10000;	//10000���ڵ��������Ϊ����ID
	this->processState = -1;		//Ĭ�Ͻ���״̬Ϊ-1����ʾδ���ɹ�new
	this->pc = 0;
	this->memorySpace = 0;
	this->priority = 0;				//Ĭ�����ȼ�Ϊ������ȼ�0

	//Ĭ��ʹ��job1��ΪĬ������
	for (int i = 0; i < JOB1.size(); i++) {
		string str = JOB1[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
	pair<int, int> nowjob;
	nowjob.first = 0;
	nowjob.second = jobs[0].getTime();
	this->nowJob = nowJob;
}

PCB::PCB(const vector<string> job)
{
	srand(seed++);
	this->processId = rand() % 10000;	//10000���ڵ��������Ϊ����ID
	this->processState = -1;		//Ĭ�Ͻ���״̬Ϊ-1����ʾδ���ɹ�new
	this->pc = 0;
	this->memorySpace = 0;
	this->priority = 0;				//Ĭ�����ȼ�Ϊ������ȼ�0
	
	this->jobs.clear();//���jobs
	for(int i = 0; i < job.size(); i++) {
		string str = job[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}

	pair<int, int> nowjob;
	nowjob.first = 0;
	nowjob.second = jobs[0].getTime();
	this->nowJob = nowJob;
}

PCB& PCB::operator=(const PCB& a)
{
	this->processId = a.processId;
	this->processState = a.processState;
	this->pc = a.pc;
	this->memorySpace = a.memorySpace;
	this->priority = a.priority;
	this->jobs = a.jobs;
	this->nowJob = a.nowJob;
	return *this;
}

PCB::PCB(const PCB& a)
{
	this->processId = a.processId;
	this->processState = a.processState;
	this->pc = a.pc;
	this->memorySpace = a.memorySpace;
	this->priority = a.priority;
	this->jobs = a.jobs;
	this->nowJob = a.nowJob;
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
	this->jobs.clear();//���jobs

	for (int i = 0; i < jobs.size(); i++) {
		string str = jobs[i];
		Operation opt = splitOperation(str, ' ');
		this->jobs.push_back(opt);
	}
}

pair<int, int> PCB::getNowJob() const
{
	return nowJob;
}

void PCB::setNowJob(pair<int, int> job)
{
	nowJob = job;
}

void PCB::show()
{
	//���������Ϣ
	cout << "processId: " << this->processId << endl
		<< "processState: " << this->processState << endl
		<< "pc: " + this->pc << endl
		<< "memorySpace: " << this->memorySpace << endl
		<< "priority: " << this->priority << endl;
	//���job
	for (int i = 0; i < jobs.size(); i++)
	{
		Operation a = jobs[i];
		cout << a.getType() << "," << a.getTime() << "," << a.getFileName() << "," << a.getFileSize() << endl;
	}
	cout << "nowJobId: " << this->nowJob.first << "," << "lastTime: " << this->nowJob.second << endl;
}