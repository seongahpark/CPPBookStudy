#ifndef _consumer_hpp_included_
#define _consumer_hpp_included_

#include "common.hpp"

typedef class consumer{

public:
	consumer();
	virtual ~consumer();

public:
	bool initialize();
	void finalize();

public:
	bool push_queue(const uint32_t number);
private:
	std::mutex _queue_lock;
	std::queue<uint32_t> _queue;

private:
	volatile bool _stop;
	std::thread* _worker_thread;
	bool consumer_worker();
}* pconsumer;

#endif	// _consumer_hpp_included_
