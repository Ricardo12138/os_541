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
	cout << "�����Ŀ¼�����ƣ�";
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
		cout << N.getName() << "���ļ��������ܴ�����һ��" << endl;
		return;
	}
	node *newnode = new node;
	node *tempnode;
	char name[10];
	bool type;
	int size;
	int state;

	cout << "��ǰ�ڵ��ļ���/Ŀ¼��:";
	cin >> name;
	(*newnode).setName(name);

	(*newnode).setParent(&N);
	(*newnode).setBro_node(NULL);
	(*newnode).setChild(NULL);
	//cout << "��ǰ�ڵ��ļ���/Ŀ¼��:" ;
	//cin >> name;
	cout << "������(0:�ļ�����1��Ŀ¼��)��";
	cin >> type;
	if (type == 0) {
		cout << "�ļ���С��";
		cin >> size;
	}
	else size = 0;
	state = 0;
	//newnode->setName(name);
	(*newnode).setType(type);
	(*newnode).setSize(size);
	(*newnode).setState(state);


	//����һ���ֵ�
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
