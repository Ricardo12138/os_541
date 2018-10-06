#include "stdafx.h"
#include "file_mangement.h"

void Delete(node N)
{
	if (N.getChild())
		Delete(*N.getChild());
	if (N.getBro_node())
		Delete(*N.getBro_node());
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
		cout << "文件大小：";
		cin >> size;
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

void Search(node N) {
	if (N.getChild())
		Search(*N.getChild());
	if(N.getBro_node())
		Search(*N.getBro_node());
	cout << N.getName() << endl;
}
