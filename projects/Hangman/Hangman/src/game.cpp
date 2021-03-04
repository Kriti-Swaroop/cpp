#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>
#include "utils.hpp"

std::vector<char> split_string(const std::string& to_split)
{
	std::vector<char> characters(to_split.begin(), to_split.end());
	return characters;
}

void fill_vector(std::vector<char>& vector, int count, char fill)
{
	std::vector<char> filled(count, fill);
	vector = filled;
}

std::vector<std::string> load_resource(const std::string& path)
{
	std::string line{};
	std::vector<std::string> lines{};
	std::ifstream resource{path};

	if (resource.good())
	{
		while (getline(resource, line))
		{
			lines.push_back(line + '\n');
		}
	}
	else
	{
		std::cerr << "File not found: " << path << '\n';
	}

	return lines;
}

struct Game
{
	std::vector<std::string> frames{};
	std::string word{};
	std::vector<char> letters{};
	std::size_t life{};
	std::vector<char> guessed{};
};

Game setup(std::string resource_path)
{
	Game hangman{};

	for (const auto& file : std::filesystem::directory_iterator(resource_path))
	{
		const auto& base = file.path().stem().string();

		if (std::all_of(base.begin(), base.end(), ::isdigit))
		{
			auto frame = load_resource(file.path().string());
			hangman.frames.push_back(std::accumulate(frame.begin(), frame.end(), std::string("")));
		}
	}

	auto all_words = load_resource(resource_path.append("/words.txt"));
	hangman.word = random_choice<std::string>(all_words);
	hangman.letters = split_string(hangman.word);
	hangman.life = hangman.frames.size() - 1;
	fill_vector(hangman.guessed, hangman.word.length(), '_');

	return hangman;
}

void print_state(Game& hangman)
{
	std::string healthbar = std::string(hangman.life, '*');
	std::cout << '\t' << "Lifepoints: ["
			  << "\033[31m" << healthbar << "\033[0m" << ']' << '\n';
	std::cout << hangman.frames[hangman.frames.size() - 1 - hangman.life] << '\n';
	std::cout << '\t';
	for (auto& placeholder : hangman.guessed)
		std::cout << placeholder << " ";
	std::cout << '\n' << '\n';
}