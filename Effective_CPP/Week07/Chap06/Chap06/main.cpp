/*************************************************
	이 프로젝트는 메시지를 producer 쓰레드에서 큐에 Push 하고, 
	consumer 쓰레드에서 큐로부터 pop 하고, 출력한다.

	이 프로젝트에서 중점적으로 봐야하는 것은,
	1. std::bind -> 할당 기능
	2. std::thread -> 쓰레드 생성 기능
	3. std::function -> 콜백함수 할당 기능
*************************************************/

#include "common.hpp"

#include "consumer.hpp"
#include "producer.hpp"

int main(void)
{
	pconsumer _consumer = new consumer();
	if (nullptr == _consumer)
	{
		return 1;
	}

	if (true != _consumer->initialize())
	{
		return 2;
	}

	pproducer _producer = new producer();
	if (nullptr == _producer)
	{
		return 1;
	}

	//
	//	Producer 객체에게 Consumer의 함수를 하나 넘겨준다.
	//
	if (true != _producer->initialize(std::bind(&consumer::push_queue,
												_consumer,
												std::placeholders::_1)))
	{
		return 2;
	}

	uint32_t number = 0;
	while (true)
	{
		if (number > 10)
		{
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		number++;
	}

	if (nullptr != _producer)
	{
		delete _producer;
		_producer = nullptr;
	}

	if (nullptr != _consumer)
	{
		delete _consumer;
		_consumer = nullptr;
	}

	return 0;
}