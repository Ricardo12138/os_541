#include "stdafx.h"
#include "Operation.h"

//·Ö¸î²Ù×÷
Operation splitOperation(const std::string &s, const char delim)
{
	Operation operation;
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	int length = elems.size();
	int times = 0;
	while (length > 0) {
		if (times == 0)
			operation.setType(elems[0]);
		else if (times == 1)
			operation.setTime(stoi(elems[1]));
		else if (times == 2)
			operation.setFileName(elems[2]);
		else if (times == 3)
			operation.setFileSize(stoi(elems[3]));
		times++;
		length--;
	}
	return operation;
}

Operation::Operation()
{
	this->type = "";
	this->time = 0;
	this->fileName = "";
	this->fileSize = 0;
}

Operation& Operation::operator=(Operation& a)
{
	this->type = a.getType();
	this->time = a.getTime();
	this->fileName = a.getFileName();
	this->fileSize = a.getFileSize();
	return *this;
}

Operation::~Operation()
{
}

string Operation::getType()
{
	return type;
}
void Operation::setType(string type)
{
	this->type = type;
}

int Operation::getTime()
{
	return time;
}
void Operation::setTime(int time)
{
	this->time = time;
}

string Operation::getFileName()
{
	return fileName;
}
void Operation::setFileName(string fileName)
{
	this->fileName = fileName;
}

int Operation::getFileSize()
{
	return fileSize;
}

void Operation::setFileSize(int fileSize)
{
	this->fileSize = fileSize;
}
