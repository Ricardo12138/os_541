#pragma once

//���̶���
static deque<Process> processQueue;
//״̬����
static deque<Process> newQueue;
static deque<Process> readyQueue;
static deque<Process> runningQueue;
static deque<Process> waitingQueue;
static deque<Process> terminatedQueue;

//״̬������Ĭ��״̬Ϊ-1����ʾδ���ɹ�new�Ľ��̣��磺�ڴ治���ԭ��
const static int newState = 0;
const static int readyState = 1;
const static int runningState = 2;
const static int waitingState = 3;
const static int terminatedState = 4;

//���񣬽���Ĭ������Ϊjob1�����鿴PCB���캯����
static const vector<string> job1 = { "M 4", "Y 2", "C 10", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q"};
static const vector<string> job2 = { "M 6", "Y 3", "C 3", "K 10", "C 2", "W b", "C 5", "P 20", "C 3", "Q" };