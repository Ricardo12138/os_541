#pragma once

//进程队列
static deque<Process> processQueue;
//状态队列
static deque<Process> newQueue;
static deque<Process> readyQueue;
static deque<Process> runningQueue;
static deque<Process> waitingQueue;
static deque<Process> terminatedQueue;

//状态常量，默认状态为-1。表示未被成功new的进程，如：内存不足等原因。
const static int newState = 0;
const static int readyState = 1;
const static int runningState = 2;
const static int waitingState = 3;
const static int terminatedState = 4;

//任务，进程默认任务为job1。详情看PCB构造函数。
static const vector<string> job1 = { "M 4", "Y 2", "C 10", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q"};
static const vector<string> job2 = { "M 6", "Y 3", "C 3", "K 10", "C 2", "W b", "C 5", "P 20", "C 3", "Q" };