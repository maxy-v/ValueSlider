#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "../ValueSlider.h"

using TestFunction = void (*)();

void test1()
{
	ValueSlider<double> s{0.5, 1.0, 1.1};
	assert(  s.value() == 1.0 );
	assert(  s.prev()         );
	assert(  s.value() == 0.5 );
	assert( !s.prev()         );
	assert(  s.next()         );
	assert(  s.value() == 1.0 );
	assert(  s.next()         );
	assert(  s.value() == 1.1 );
	assert( !s.next()         );
}

void test2()
{
	ValueSlider<std::string,1> s{"zero", "one", "two"};
	assert( s.value() == "one" );
}

void test3()
{
	ValueSlider<std::string,0> s{"zero", "one", "two"};
	assert( s.value() == "zero" );
}

int main()
{
	std::vector<TestFunction> tests = { test1, test2, test3 };
	int index = 0;
	for (auto& test: tests)
	{
		std::cout << "Test " << index++ << ": ";
		test();
		std::cout << "success" << std::endl;
	}
	return 0;
}