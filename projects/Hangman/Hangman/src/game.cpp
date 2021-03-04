#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <thread>
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
			lines.push_back('\t' + line + '\n');
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
	std::vector<std::string> frames{};	// hangman ascii art
	std::string word{};					// word to guess
	std::vector<char> letters{};		// generated from word
	std::size_t life{};					// current life points
	std::size_t max_life{};				// used for padding the healthbar
	std::vector<char> guessed{};		// progress feedback
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
	hangman.max_life = hangman.life;
	fill_vector(hangman.guessed, hangman.word.length(), '_');

	return hangman;
}

void print_splash_screen(std::string resource_path)
{
	auto splash = load_resource(resource_path.append("/splash.txt"));
	// fg-color: green
	std::cout << '\n' << "\033[33m" << std::accumulate(splash.begin(), splash.end(), std::string("")) << "\033[0m" << '\n';
	std::cout << '\t' << "ahvy sazl wny nrbbguz fo lvu oe davk sugpoj setkzdf";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	// clear screen
	std::cout << "\033[2J\033[1;1H";
}

void print_state(Game& hangman)
{
	std::string healthbar = std::string(hangman.life, '*');
	// pad with trailing whitespaces
	healthbar = healthbar.append(std::string(hangman.max_life - hangman.life, ' '));
	std::cout << '\n'
			  << '\t' << "Lifepoints: ["
			  << "\033[31m" << healthbar << "\033[0m" << ']' << '\n';  // fg-color: red
	std::cout << hangman.frames[hangman.frames.size() - 1 - hangman.life] << '\n';
	std::cout << '\t';
	for (auto& placeholder : hangman.guessed)
		std::cout << "\033[33m" << placeholder << "\033[0m ";
	std::cout << std::string(2, '\n');
}