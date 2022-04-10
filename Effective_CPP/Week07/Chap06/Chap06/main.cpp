/*************************************************
	�� ������Ʈ�� �޽����� producer �����忡�� ť�� Push �ϰ�, 
	consumer �����忡�� ť�κ��� pop �ϰ�, ����Ѵ�.

	�� ������Ʈ���� ���������� �����ϴ� ����,
	1. std::bind -> �Ҵ� ���
	2. std::thread -> ������ ���� ���
	3. std::function -> �ݹ��Լ� �Ҵ� ���
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
	//	Producer ��ü���� Consumer�� �Լ��� �ϳ� �Ѱ��ش�.
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