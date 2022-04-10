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
	//	������� ������ �Լ��� std::bind�� ���� �Ҵ��Ѵ�.
	//	std::bind�� �ι�° �Ű������� �ش� ��ü ��ü�� �ּҸ� �ѱ�� �ǹ��Դϴ�.
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
		//	������ ����� ������ ���.
		//
		_worker_thread->join();

		delete _worker_thread;
		_worker_thread = nullptr;
	}
}

bool 
consumer::push_queue(const uint32_t number)
{
	//	��ȣ�� ������, �˾Ƽ� lock�� ������.
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
			//	��ȣ�� ������, �˾Ƽ� lock�� ������.
			std::lock_guard<std::mutex> lock(_queue_lock);
			//	������ �ּ� ó���� ���� �������
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
