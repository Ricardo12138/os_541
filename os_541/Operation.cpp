#include "stdafx.h"
#include "Operation.h"
#include "global.h"

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
		{
			if (elems[0] == IT_M)
				operation.setBlock(stoi(elems[1]));
			else if (elems[0] == IT_Y)
				operation.setPriorityNumber(stoi(elems[1]));
			else
				operation.setTime(stoi(elems[1]));
		}
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
	this->block = 0;
	this->priorityNumber = 0;
}

Operation::Operation(const Operation& a)
{
	this->type = a.type;
	this->time = a.time;
	this->fileName = a.fileName;
	this->fileSize = a.fileSize;
	this->block = a.block;
	this->priorityNumber = a.priorityNumber;
}

Operation& Operation::operator=(const Operation& a)
{
	this->type = a.type;
	this->time = a.time;
	this->fileName = a.fileName;
	this->fileSize = a.fileSize;
	this->block = a.block;
	this->priorityNumber = a.priorityNumber;
	return *this;
}

Operation::~Operation()
{
}

string Operation::getType() const
{
	return type;
}
void Operation::setType(string type)
{
	this->type = type;
}

int Operation::getTime() const
{
	return time;
}
void Operation::setTime(int time)
{
	this->time = time;
}

string Operation::getFileName() const
{
	return fileName;
}
void Operation::setFileName(string fileName)
{
	this->fileName = fileName;
}

int Operation::getFileSize() const
{
	return fileSize;
}

void Operation::setFileSize(int fileSize)
{
	this->fileSize = fileSize;
}

int Operation::getBlock() const
{
	return block;
}

void Operation::setBlock(int block)
{
	this->block = block;
}

int Operation::getPriorityNumber() const
{
	return priorityNumber;
}

void Operation::setPriorityNumber(int number)
{
	priorityNumber = number;
}
