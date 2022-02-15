// Week04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <iostream>

class Investment{
public:
	Investment()
	{
		std::cout << "Create Investment" << std::endl;
	}
	~Investment()
	{
		std::cout << "delete Investment" << std::endl;
	}
};
class Example {
public:
	Example() {}
	explicit Example(const Example& ex) {}
	Example& operator=(const Example& ex) {}
};
void test(Example ex) {}

void item13()
{
	std::auto_ptr<Investment> pInv(new Investment());
	//	Memory Leak!!!!
	//Investment* pInv = new Investment();
}

void item14()
{
	return;
}

int daysHeld(const Investment* pi)
{
	return 0;
}
void item15()
{
	std::tr1::shared_ptr<Investment> pInv(new Investment());
	//	Compile Error
	//	int res = daysHeld(pInv);
	int res = daysHeld(pInv.get());
}

void item16()
{
	std::string *stringPtr1 = new std::string[100];

	delete[] stringPtr1;
}

void item17()
{
	Example ex;
	//test(Example());
	//test(ex);
}

void auto_ptr_problem1(size_t n)
{
	std::auto_ptr<Investment> p1(new Investment);
	std::auto_ptr<Investment> p2(new Investment[n]);
	//
	//	배열포인터에 auto_ptr을 사용하면 해제가 올바르게 되지 않습니다.
	//
}

int main()
{
	_CrtMemState memoryState = { 0 };
	_CrtMemCheckpoint(&memoryState);
	{
		item13();
		item15();
		item16();
		auto_ptr_problem1(10);
	}
	_CrtMemDumpAllObjectsSince(&memoryState);

	return 0;
}