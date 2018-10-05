#pragma once

//�����ࡣ�����񻮷ֳɸ�������
class Operation
{
private:
	string type; //��������
	int time; //��������ʱ��
	string fileName; //�ļ���
	int fileSize;//�ļ���С
	int block;//�ڴ�ռ�
	int priorityNumber;//���ȼ���
public:
	Operation();
	Operation& operator=(const Operation& a);
	Operation(const Operation& a);
	~Operation();

	string getType() const;
	void setType(string type);

	int getTime() const;
	void setTime(int time);

	string getFileName() const;
	void setFileName(string fileName);
	
	int getFileSize() const;
	void setFileSize(int fileSize);

	int getBlock() const;
	void setBlock(int block);

	int getPriorityNumber() const;
	void setPriorityNumber(int number);
};


//�ָ����
Operation splitOperation(const std::string &s, const char delim);
