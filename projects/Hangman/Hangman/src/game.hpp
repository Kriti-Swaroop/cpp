#pragma once
#include <string>
#include <vector>

std::vector<char> split_string(const std::string& to_split);
std::vector<char> fill_vector(int count, char fill);

struct Game
{
	std::vector<std::string> frames{};
	std::string word{};
	std::vector<char> letters{};
	int life{};
	std::size_t max_life{};
	std::vector<char> guessed{};
};

std::vector<std::string> load_resource(const std::string& path);
Game setup(std::string resource_path);
void print_splash_screen(std::string resource_path);
void print_state(Game& hangman);