#include "stdafx.h"
#include "Process.h"
#include "PCB.h"
#include "TC_ThreadQueue.h"

struct {
	bool operator()(Process a, Process b) const
	{
		PCB aPCB = a.getPCB();
		PCB bPCB = b.getPCB();
		int aPriority = aPCB.getPriority();
		int bPriority = bPCB.getPriority();
		return aPriority < bPriority;
	}
} prioritySchedule;
/*
void prioritySort(deque<Process>& dq) {
	try
	{
		std::sort(dq.begin(), dq.end(), prioritySchedule);
	}
	catch (exception e)
	{
		cout << "****" << endl;
	}
}*/

/*void prioritySort(concurrent_queue<Process>& dq) {
	try
	{
		std::sort(dq.begin(), dq.end(), prioritySchedule);
	}
	catch (exception e)
	{
		cout << "****" << endl;
	}
}*/