#pragma once
#include <string>
#include <vector>

int random_range(const int& min, const int& max);
std::string random_choice(const std::vector<std::string>& vector);
std::vector<char> split_string(const std::string& to_split);

template <typename T> T get_user_input(std::string msg)
{
	std::cout << msg;
	T input{};
	std::cin >> input;
	return input;
}

struct Game
{
	std::vector<std::string> frames{};
	std::string word{};
	std::vector<char> characters{};
	int life{};
};

std::vector<std::string> load_resource(const std::string& path);
std::string join_vector(const std::vector<std::string>& vector);
Game setup(std::string resource_path);