#include "stdafx.h"
#include "memory.h"

cPartition *head = NULL;	//连续分区的头指针	

/*
** 连续分区初始化
** 初始化成功返回1，否则返回-1
*/
STATUS initialization()
{
	if (!(head = (cPartition*)malloc(sizeof(cPartition))))
	{
		return WRONG;
	}
	head->size = MAXSIZE;
	head->state = FREE;
	head->address = 0;
	head->processID = -1;
	head->next = NULL;
	return OK;
}

/*
** 连续分区分配内存,采用最佳匹配法
** 接收参数：请求内存的大小，进程ID
** 分配成功返回该内存块的首地址，否则返回-1
*/
STATUS allocation(int request, int processID)
{
	cPartition *p = head;
	cPartition *best = NULL;
	int difference = 99999;
	while (p)
	{
		if (p->state == FREE && p->size >= request)
		{
			if (p->size - request < difference)
			{
				difference = p->size - request;
				best = p;
			}
		}
		p = p->next;
	}

	if (!best)
	{
		return WRONG;
	}
	else
	{
		cPartition *temp = (cPartition*)malloc(sizeof(cPartition));

		temp->size = best->size - request;
		temp->state = FREE;
		temp->processID = -1;
		temp->address = best->address + request;
		temp->next = best->next;

		best->size = request;
		best->state = BUSY;
		best->processID = processID;
		if (temp->size > 0)
		{
			best->next = temp;
		}
		return best->address;
	}
}

/*
** 连续分区回收内存
** 接收参数：内存块的起始地址
** 回收成功返回1，否则返回-1
*/
STATUS recycle(int address)
{
	cPartition *p = head;
	cPartition *prior = p;

	while (p && p->address != address)
	{
		prior = p;
		p = p->next;
	}

	if (!p)
	{
		return WRONG;
	}

	cPartition *next = p->next;
	//若p是头指针
	if (p == prior)
	{
		prior = (cPartition*)malloc(sizeof(cPartition));
		prior->address = 0;
		prior->state = BUSY;
		prior->size = 0;
		prior->next = NULL;
	}
	//若p是尾指针
	if (next == NULL)
	{
		next = (cPartition*)malloc(sizeof(cPartition));
		next->state = BUSY;
		next->size = 0;
		next->next = NULL;
	}

	if (prior->state == BUSY && next->state == BUSY)
	{
		p->state = FREE;
		p->processID = -1;
	}
	else if (prior->state == BUSY && next->state == FREE)
	{
		p->state = FREE;
		p->processID = -1;
		p->size = p->size + next->size;
		p->next = next->next;
		free(next);
		next = NULL;
	}
	else if (prior->state == FREE && next->state == BUSY)
	{
		prior->size = prior->size + p->size;
		prior->next = p->next;
		free(p);
		p = NULL;
	}
	else
	{
		prior->size = prior->size + p->size + next->size;
		prior->next = next->next;
		free(p);
		free(next);
		p = NULL;
		next = NULL;
	}
	return OK;
}

/*
** 内存的使用情况
** 用链表形式返回内存的使用情况
*/
useCondition* show()
{
	cPartition *p = head;

	useCondition* use = (useCondition*)malloc(sizeof(useCondition));
	useCondition* usehead = use;
	use->address = p->address;
	use->size = p->size;
	use->state = p->state;
	use->processID = p->processID;
	use->next = NULL;

	p = p->next;
	while (p)
	{
		useCondition* temp = (useCondition*)malloc(sizeof(useCondition));
		temp->address = p->address;
		temp->size = p->size;
		temp->state = p->state;
		temp->processID = p->processID;
		temp->next = NULL;

		use->next = temp;
		use = use->next;
		p = p->next;
	}
	return usehead;
}