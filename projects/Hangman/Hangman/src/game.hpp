#pragma once
#include <string>
#include <vector>

std::vector<char> split_string(const std::string& to_split);

struct Game
{
	std::vector<std::string> frames{};
	std::string word{};
	std::vector<char> characters{};
	int life{};
};

std::vector<std::string> load_resource(const std::string& path);
Game setup(std::string resource_path);