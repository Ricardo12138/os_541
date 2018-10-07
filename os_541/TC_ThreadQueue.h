#pragma once

template<typename Data>
class concurrent_queue
{
private:
	std::deque<Data> the_queue;
	std::mutex the_mutex;
	std::condition_variable the_condition_variable;

public:
	void push_back(Data const& data)
	{
#if 0
		std::lock_guard<std::mutex> lock(the_mutex);
		the_queue.push(data);
		lock.unlock();
#else   //利用作用域自动释放锁，防止异常崩溃场景
		{
			std::lock_guard<std::mutex> lock(the_mutex);
			the_queue.push_back(data);
		}
#endif
		the_condition_variable.notify_one();
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		return the_queue.empty();
	}

	//获取队列头部的值，并移除队列头部
	bool try_pop(Data& popped_value)
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		if (the_queue.empty())
		{
			return false;
		}

		popped_value = the_queue.front();
		the_queue.pop_front();
		return true;
	}

	void pop_front()
	{
		//cout << the_queue.size() << endl;
		std::lock_guard<std::mutex> lock(the_mutex);
		Process process = the_queue.front();
		the_queue.pop_front();
	}

	Data& front()
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		return the_queue.front();
	}

	//等待队列有值，再弹出队列的头部
	void wait_and_pop(Data& popped_value)
	{
		std::lock_guard<std::mutex> lock(the_mutex);
		while (the_queue.empty())
		{
			the_condition_variable.wait(lock);
		}

		popped_value = the_queue.front();
		the_queue.pop_front();
	}

	struct {
		bool operator()(Process a, Process b) const
		{
			PCB aPCB = a.getPCB();
			PCB bPCB = b.getPCB();
			int aPriority = aPCB.getPriority();
			int bPriority = bPCB.getPriority();
			return aPriority < bPriority;
		}
	} prioritySchedule1;

	void prioritySort1() {
		std::lock_guard<std::mutex> lock(the_mutex);
		std::sort(the_queue.begin(), the_queue.end(), prioritySchedule1);
	}

};
