#include"stdafx.h"
#include "file.h"

node::node()
{
	strcpy_s(this->name, "");
	this->type = 0;
	this->size = 0;
	this->state = 0;
	this->child = NULL;
	this->bro_node = NULL;
}

node & node::operator=(const node & N)
{
	strcpy_s(this->name, N.name);
	this->type = N.type;
	this->size = N.size;
	this->state = N.state;
	this->child = N.child;
	this->bro_node = N.bro_node;
	this->parent = N.parent;
	return *this;
}
bool node::operator==(node & N)
{
	int i = strcmp(this->getName(), N.getName());
	if (i == 0)
		return true;
	return false;
}
/*
node *& node::operator=(const node *& N)
{
	strcpy_s(this->name, (*N).name);
	this->type = (*N).type;
	this->size = (*N).size;
	this->state = (*N).state;
	this->child = (*N).child;
	this->bro_node = (*N).bro_node;
	this->parent = (*N).parent;
	return **this;
}*/

node::~node()
{
}

char* node::getName()
{
	return name;
}

void node::setName(char name[])
{
	strcpy_s(this->name, name);
}

bool node::getType()
{
	return type;
}

void node::setType(bool type)
{
	this->type = type;
}

int node::getSize()
{
	return size;
}

void node::setSize(int size)
{
	this->size = size;
}

int node::getState()
{
	return state;
}

void node::setState(int state)
{
	this->state = state;
}

node * node::getChild()
{
	return this->child;
}

void node::setChild(node * child)
{
	this->child = child;
}

node * node::getBro_node()
{
	return bro_node;
}

void node::setBro_node(node * bro_node)
{
	this->bro_node = bro_node;
}

node * node::getParent()
{
	return parent;
}

void node::setParent(node * parent)
{
	this->parent = parent;
}
