#pragma once
#include <string>
#include <vector>

std::vector<char> split_string(const std::string& to_split);
void fill_vector(std::vector<char>& vector, int count, char fill);

struct Game
{
	std::vector<std::string> frames{};
	std::string word{};
	std::vector<char> letters{};
	int life{};
};

std::vector<std::string> load_resource(const std::string& path);
Game setup(std::string resource_path);
void print_state(Game& hangman);