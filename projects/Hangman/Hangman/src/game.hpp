#pragma once

//#include <type_traits>

void test();

template <typename T> T get_user_input(std::string msg)
{
	std::cout << msg;
	T input{};
	std::cin >> input;
	return input;
}