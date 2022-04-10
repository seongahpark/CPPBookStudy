#include "consumer.hpp"

consumer::consumer()
	:
	_stop(false),
	_worker_thread(nullptr)
{
}

consumer::~consumer()
{
	finalize();
}

bool consumer::initialize()
{
	_ASSERTE(true != _stop);
	_ASSERTE(nullptr == _worker_thread);
	if (nullptr != _worker_thread || true == _stop)
	{
		return false;
	}

	//
	//	쓰레드로 생성할 함수를 std::bind를 통해 할당한다.
	//	std::bind의 두번째 매개변수는 해당 객체 전체의 주소를 넘기는 의미입니다.
	//
	_worker_thread = new std::thread(std::bind(&consumer::consumer_worker,
											   this));

	if (nullptr == _worker_thread)
	{
		return false;
	}
	
	return true;
}

void consumer::finalize()
{
	_stop = true;

	if (nullptr != _worker_thread)
	{
		//
		//	쓰레드 종료될 때까지 대기.
		//
		_worker_thread->join();

		delete _worker_thread;
		_worker_thread = nullptr;
	}
}

bool 
consumer::push_queue(const uint32_t number)
{
	//	괄호가 끝나면, 알아서 lock이 해제됨.
	std::lock_guard<std::mutex> lock(_queue_lock);
	_queue.push(number);

	return true;
}

bool 
consumer::consumer_worker()
{
	_ASSERTE(true != _stop);
	if(true == _stop)
	{
		return false;
	}

	uint32_t temp = 0;

	while (!_stop)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(100));
		{
			//	괄호가 끝나면, 알아서 lock이 해제됨.
			std::lock_guard<std::mutex> lock(_queue_lock);
			//	원래는 주석 처리와 같이 사용했음
			//	_queue_lock.lock();
			if (_queue.empty())
			{
				continue;
			}

			temp = _queue.front();
			_queue.pop();

			std::cout << "_queue.pop value : " << temp << std::endl;
			//	_queue_lock.unlock();
		}
	}

	return true;
}
