#pragma once

void eraseQueueElem(deque<Process>& dq, Process process);

void running();
pair<bool, bool> runningJob(Process& process);