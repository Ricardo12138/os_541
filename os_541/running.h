#pragma once

void eraseQueueElem(deque<Process>& dq, Process process);

void running(string scheduleType);
pair<bool, bool> runningFCFS(Process& process);