// Week04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <iostream>

class Investment{};
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
	//	Investment* pInv = new Investment();
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

int main()
{
	_CrtMemState memoryState = { 0 };
	_CrtMemCheckpoint(&memoryState);
	{
		item13();
		item15();
		item16();
	}
	_CrtMemDumpAllObjectsSince(&memoryState);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
