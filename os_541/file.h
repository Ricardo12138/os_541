#pragma once

class node
{
private:
	char name[10];//文件名/目录名
	bool type;// 0      /1
	int size;//文件大小，目录名时为0
	int state;//空闲：0/读：1/写：2,默认为0
	node *child;//文件名时为null
	node *bro_node;
	node *parent;//父节点
public:
	node();
	node& operator=(const node& N);
	bool operator==(node& N);
	~node();

	char* getName();
	void setName(char name[]);

	bool getType();
	void setType(bool type);

	int getSize();
	void setSize(int size);

	int getState();
	void setState(int state);

	node * getChild();
	void setChild(node * child);

	node * getBro_node();
	void setBro_node(node * bro_node);

	node * getParent();
	void setParent(node * parent);
};
