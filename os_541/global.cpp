#include "global.h"
#include "stdafx.h"
#include "Process.h"
#include"file.h"
#include "TC_ThreadQueue.h"
/*
//×´Ì¬¶ÓÁÐ
deque<Process> newQueue;
deque<Process> readyQueue;
deque<Process> runningQueue;
deque<Process> waitingQueue;
deque<Process> terminatedQueue;
*/

concurrent_queue<Process> newQueue;
concurrent_queue<Process> readyQueue;
concurrent_queue<Process> runningQueue;
concurrent_queue<Process> waitingQueue;
concurrent_queue<Process> terminatedQueue;

node Root;