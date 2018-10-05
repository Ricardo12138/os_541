#pragma once

//操作类。把任务划分成各个操作
class Operation
{
private:
	string type; //操作类型
	int time; //操作工作时间
	string fileName; //文件名
	int fileSize;//文件大小
	int block;//内存空间
	int priorityNumber;//优先级数
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


//分割操作
Operation splitOperation(const std::string &s, const char delim);
