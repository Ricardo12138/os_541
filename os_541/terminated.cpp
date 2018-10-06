#include "terminated.h"

void terminated()
{
	while (1)
	{
		if (!terminatedQueue.empty())
		{
			Process pro = terminatedQueue.front();
			PCB pcb = pro.getPCB();
			if (recycle(pcb.getaddr))
			{
				cout << "recycle error!" << endl;
				return;
			}
			terminatedQueue.pop_front();
		}
	}
}