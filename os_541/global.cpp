#include "global.h"
#include "stdafx.h"
#include "Process.h"
//״̬����
deque<Process> newQueue;
deque<Process> readyQueue;
deque<Process> runningQueue;
deque<Process> waitingQueue;
deque<Process> terminatedQueue;