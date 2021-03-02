#pragma once
#include <string>
#include <vector>

void test();

template <typename T> T get_user_input(std::string msg)
{
	std::cout << msg;
	T input{};
	std::cin >> input;
	return input;
}

std::vector<std::string> load_resource(const std::string& path);
std::string join_vector(const std::vector<std::string>& vector);