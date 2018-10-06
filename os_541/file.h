#pragma once

class node
{
private:
	char name[10];//�ļ���/Ŀ¼��
	bool type;// 0      /1
	int size;//�ļ���С��Ŀ¼��ʱΪ0
	int state;//���У�0/����1/д��2,Ĭ��Ϊ0
	node *child;//�ļ���ʱΪnull
	node *bro_node;
	node *parent;//���ڵ�
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
