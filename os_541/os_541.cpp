// os_541.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Process.h"
#include "pcb.h"
#include "scheduleAlgorithm.h"
#include "global.h"
#include "Operation.h"
#include "running.h"
#include "run.h"
#include<iostream>
#include<vector>
#include"file_mangement.h"
#include "new.h"
#include "memory.h"
#include "ProducerConsumer.h"
using namespace std;

int main()
{
	Root = Create(); //��ʼ���ļ���

	initialization();//��ʼ���ڴ�

	//��������
	produce(job1);
	produce(job2);
	produce(job3);
	produce(job4);
	produce(job5);

	startProducerConsumer();//�����������������߳�

	run();//�������̵��ȵ�5���߳�

	return 0;
	
}

