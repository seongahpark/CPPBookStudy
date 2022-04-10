#ifndef _producer_hpp_included_
#define _producer_hpp_included_

#include "common.hpp"

typedef class producer {

public:
	producer();
	virtual ~producer();

public:
	bool initialize(push_queue fn_push);
	void finalize();

private:
	push_queue _fn_push;

private:
	volatile bool _stop;
	std::thread* _worker_thread;
	bool producer_worker();

}* pproducer;

#endif	// _producer_hpp_included_
