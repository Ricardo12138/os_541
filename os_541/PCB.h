#pragma once
#include "Operation.h"

class PCB
{
private:
	int processId;		//����id
	int processState;	//���̵�ǰ״̬
	int pc;				//���������
	int memorySpace;	//�ڴ�ռ�
	int priority; //�������ȼ�
	vector<Operation> jobs;	//��Ӧ����
	pair<int, int> nowJob; //����ִ�е������տ�ʼ������1���ڼ�����2��ʣ��ʱ��

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

