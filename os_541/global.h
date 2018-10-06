#pragma once
#include "Process.h"
#include"file.h"

//状态队列
extern deque<Process> newQueue;
extern deque<Process> readyQueue;
extern deque<Process> runningQueue;
extern deque<Process> waitingQueue;
extern deque<Process> terminatedQueue;

//状态常量，默认状态为-1。表示未被成功new的进程，如：内存不足等原因。
const int newState = 0;
const int readyState = 1;
const int runningState = 2;
const int waitingState = 3;
const int terminatedState = 4;

//任务，进程默认任务为job1。详情看PCB构造函数。
const vector<string> job1 = { "C 10", "I", "R 4 a 20", "C 5", "W 4 a 20", "C 2", "Q"};
const vector<string> job2 = { "C 3", "K 10", "C 2", "W 5 b 40", "C 5", "P 20", "C 3", "Q" };
const vector<string> job3 = { "K 4", "C 3", "P 5", "Q" };
const vector<string> job4 = { "C 9", "C 5", "C 10", "Q" };
const vector<string> job5 = { "R 4 a 10", "I", "W 4 a 10", "Q" };

//系统时钟
const int TIME = 1000;

//时间种子
static time_t seed = time(0);

//调度算法
const string SA_PRIORITY = "PSA"; //优先级调度
const string SA_FCFS = "FCFS"; //先来先服务
const string SA_RR = "RR"; //轮询

//指令类型
const string IT_M = "M";
const string IT_Y = "Y";
const string IT_C = "C";
const string IT_I = "I";
const string IT_R = "R";
const string IT_W = "W";
const string IT_Q = "Q";
const string IT_K = "K";
const string IT_P = "P";


extern node Root;