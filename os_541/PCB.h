#pragma once
#include "Operation.h"
class PCB
{
private:
	int processId;		//����id
	int processState;	//���̵�ǰ״̬
	int pc;				//���������
	int memoryAddress;	//�ڴ��ַ
	int priority; //�������ȼ�
	vector<Operation> jobs;	//��Ӧ����

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

