#include "stdafx.h"
#include "file_mangement.h"
#include"global.h"

void Delete(node N)
{
	if (N.getChild())
		Delete(*N.getChild());
	Size = N.getSize() + Size;

	if (N.getParent()->getChild()->getName() == N.getName())
		N.getParent()->setChild(N.getBro_node());
	else {
		node *tempnode = N.getParent()->getChild();
		while (tempnode->getBro_node()->getName() == N.getName())
			tempnode = tempnode->getBro_node();
		tempnode->setBro_node(N.getBro_node());
	}

	delete &N;
}

node Create()
{
	node newnode;
	char name[10];
	cout << "输入根目录的名称：";
	cin >> name;
	newnode.setName(name);
	newnode.setType(1);
	newnode.setSize(0);
	newnode.setState(0);
	newnode.setChild(NULL);
	newnode.setBro_node(NULL);
	newnode.setParent(NULL);
	return newnode;
}

void Add(node& N)
{
	if (N.getType() == 0)
	{
		cout << N.getName() << "是文件名，不能创建下一级" << endl;
		return;
	}
	node *newnode = new node;
	node *tempnode;
	char name[10];
	bool type;
	int size;
	int state;

	cout << "当前节点文件名/目录名:";
	cin >> name;
	(*newnode).setName(name);

	(*newnode).setParent(&N);
	(*newnode).setBro_node(NULL);
	(*newnode).setChild(NULL);
	//cout << "当前节点文件名/目录名:" ;
	//cin >> name;
	cout << "请输入(0:文件名；1：目录名)：";
	cin >> type;
	if (type == 0) {
		cout << "文件剩余大小为：" << Size << endl;
		cout << "文件大小：";
		cin >> size;
		while (Size < size)
		{
			cout << "文件剩余大小为：" << Size << endl;
			cout << "请重新输入：" << endl;
			cout << "文件大小：";
			cin >> size;
		}
		Size = Size - size;
	}
	else size = 0;
	state = 0;
	//newnode->setName(name);
	(*newnode).setType(type);
	(*newnode).setSize(size);
	(*newnode).setState(state);


	//找上一个兄弟
	if (N.getChild() == NULL)
		N.setChild(newnode);

	else {
		tempnode = N.getChild();
		while (tempnode->getBro_node() != NULL)
			tempnode = tempnode->getBro_node();
		tempnode->setBro_node(newnode);
	}
}

bool Search(node N, string target) {
	char buf[10];
	strcpy(buf, target.c_str());
	if (strcmp(N.getName() , buf) == 0)
	{
		T = 1;
		return T;
	}

	if (N.getChild())
		Search(*N.getChild(), target);
	if (N.getBro_node())
		Search(*N.getBro_node(), target);
	//cout << N.getName() << endl;
	return T;
}

bool SearchFile(node N, string target) {
	char buf[10];
	strcpy(buf, target.c_str());
	if (strcmp(N.getName(), buf) == 0 && N.getType() == 0)
	{
		T = 1;
		return T;
	}

	if (N.getChild())
		Search(*N.getChild(), target);
	if (N.getBro_node())
		Search(*N.getBro_node(), target);
	//cout << N.getName() << endl;
	return T;
}

void Write(node N, string filename, int time, int size)
{
	char buf[10];
	strcpy(buf, filename.c_str());
	if (N.getChild())
		Write(*N.getChild(),filename,time,size);
	if(N.getBro_node())
		Write(*N.getBro_node(), filename, time, size);
	if (strcmp(N.getName() , buf) == 0 && N.getType() == 0)
	{
		N.setState(2);
		Sleep(time);
		N.setSize(N.getSize() + size);
		N.setState(0);
	}
}

void Read(node N, string filename, int time)
{
	char buf[10];
	strcpy(buf, filename.c_str());
	if (N.getChild())
		Read(*N.getChild(), filename, time);
	if (N.getBro_node())
		Read(*N.getBro_node(), filename, time);
	if (strcmp(N.getName() , buf) == 0 && N.getType() == 0)
	{
		N.setState(1);
		Sleep(time);
		N.setState(0);
	}
}

void fileWrite(string filename, int time, int size) {
	int result = SearchFile(Root, filename);
	if (result == 1)
		Write(Root, filename, time, size);
	else {
		Add(Root);
		Write(Root, filename, time, size);
	}
}

bool fileRead(string filename, int time)
{
	int result = SearchFile(Root, filename);
	if (result == 1) {
		Read(Root, filename, time);
		return true;
	}		
	return false;
}
