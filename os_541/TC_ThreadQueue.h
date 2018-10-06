#pragma once
#include"stdafx.h"

template<typename T, typename D = deque<T> >
class TC_ThreadQueue : protected TC_ThreadLock
{
public:
	typedef D queue_type;
	bool pop_front(T& t, size_t millsecond = 0)
	{
		Lock lock(*this);
		if (_queue.empty())
		{
			if (millsecond == 0)
			{
				return false;
			}
			timedWait(millsecond);
		}
		if (_queue.empty())	
		{
			return false;
		}
		t = _queue.front();
		_queue.pop_front(); 
		return true;
	}

	void notifyT()
	{
		Lock lock(*this);
		notifyAll();
	}

	void push_back(const T& t)
	{
		Lock lock(*this);
		if (_queue.empty())
		{
			notifyAll();
		}	_queue.push_back(t);
	}
		
	bool swap(queue_type &q, size_t millsecond = 0)
	{
		Lock lock(*this);
		if (_queue.empty())
		{
			if (millsecond == 0)
			{
				return false;
			}
			timedWait(millsecond);
		}
		if (_queue.empty())
		{
			return false;
		}
		q.swap(_queue);
		return true;
	}
		
	size_t size() const
	{
		Lock lock(*this);
		return _queue.size();
	}
		
	void clear()
	{
		Lock lock(*this);
		_queue.clear();
	}
		
	bool empty() const
	{
		Lock lock(*this);
		return _queue.empty();
	}
protected:
		
	queue_type _queue;
};

