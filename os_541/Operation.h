#pragma once

class Operation
{
private:
	string type;
	int time;
	string fileName;
	int fileSize;
public:
	Operation();
	Operation& operator=(Operation& a);
	~Operation();

	string getType();
	void setType(string type);

	int getTime();
	void setTime(int time);

	string getFileName();
	void setFileName(string fileName);
	
	int getFileSize();
	void setFileSize(int fileSize);
};


//·Ö¸î²Ù×÷
Operation splitOperation(const std::string &s, const char delim);
