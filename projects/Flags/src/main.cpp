#include <iostream>
#include <bitset>
#include "flag.hpp"

int main()
{
	/*
	 * foo = 123456
	 * 
	 *  [8]  [7]  [6]  [5]  [4]  [3]  [2]  [1]     bytes
	 * 0000'0000'0000'0001'1110'0010'0100'0000     bits
	 *                   ^ ^^^    ^   ^ 
	 *                   1 111    1   7
	 *                   7 654    0
	 */
	std::uint_fast32_t foo{ 123456 };
	
#pragma region Testing All Flag Methods

	std::cout << "Using number " << foo << '\t' << std::bitset<32>(foo) << '\n' << '\n';

	// 0	(foo=123456)
	std::cout << "Test flag1" << '\n';
	std::cout << std::string(20, '-') << '\n';
	std::cout << test(foo, Flags::flag1) << '\t' << "(foo=" << foo << ')' << '\n' << '\n';
	
	// 1	(foo=1234567)
	std::cout << "Set flag1" << '\n';
	std::cout << std::string(20, '-') << '\n';
	set(foo, Flags::flag1);
	std::cout << test(foo, Flags::flag1) << '\t' << "(foo=" << foo << ')' << '\n' << '\n';

	// 0	(foo=123456)
	std::cout << "Reset flag1" << '\n';
	std::cout << std::string(20, '-') << '\n';
	reset(foo, Flags::flag1);
	std::cout << test(foo, Flags::flag1) << '\t' << "(foo=" << foo << ')' << '\n' << '\n';

	// 1	(foo=1234567)
	std::cout << "Flip flag1" << '\n';
	std::cout << std::string(20, '-') << '\n';
	flip(foo, Flags::flag1);
	std::cout << test(foo, Flags::flag1) << '\t' << "(foo=" << foo << ')' << '\n' << '\n';

	// check if flag 1,7,10,14,15,16,17 are set
	if (foo & (Flags::flag1 | Flags::flag7 | Flags::flag10 | Flags::flag14 | Flags::flag15 | Flags::flag16 | Flags::flag17))
		std::cout << "pass" << '\n';
	
#pragma endregion

	std::cin.get();
}