#include "producer.hpp"

producer::producer()
	:
	_worker_thread(nullptr),
	_stop(false)
{

}

producer::~producer()
{
	finalize();
}

bool 
producer::initialize(push_queue fn_push)
{
	_ASSERTE(nullptr == _worker_thread);
	if (nullptr != _worker_thread)
	{
		return false;
	}

	//
	//	콜백함수를 객체에게 할당한다.
	//	즉, consumer객체에서 push_queue라는 함수를 제공
	//
	_fn_push = fn_push;

	_worker_thread = new std::thread(std::bind(&producer::producer_worker,
											   this));
	if (nullptr == _worker_thread)
	{
		std::cout << "producer_worker thread creation failed." << std::endl;
		return false;
	}

	return true;
}

void producer::finalize()
{
	_stop = true;

	if (nullptr != _worker_thread)
	{
		_worker_thread->join();

		delete _worker_thread;
		_worker_thread = nullptr;
	}
}

bool 
producer::producer_worker()
{
	_ASSERTE(true != _stop);
	if (true == _stop)
	{
		return false;
	}

	uint32_t number = 0;

	while (!_stop)
	{
		if (true != _fn_push(number))
		{
			std::cout << "_fn_push failed. number : " << number << std::endl;
			break;
		}

		number++;
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}

	return true;
}

