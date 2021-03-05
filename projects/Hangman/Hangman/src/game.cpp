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

void strip_char(std::string& word, const char& escape_sequence)
{
	word.erase(remove(word.begin(), word.end(), escape_sequence), word.end());
}

std::vector<char> fill_vector(int count, char fill)
{
	std::vector<char> filled(count, fill);
	return filled;
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

	// load_resource adds '\t' and '\n' to lines of strings
	// for formatting, so we need to remove them first
	auto random_word = random_choice<std::string>(all_words);
	strip_char(random_word, '\t');
	strip_char(random_word, '\n');

	hangman.word = random_word;
	hangman.letters = split_string(hangman.word);
	hangman.life = hangman.frames.size() - 1;
	hangman.max_life = hangman.life;
	hangman.guessed = fill_vector(hangman.word.length(), '_');

	return hangman;
}

void print_splash_screen(std::string resource_path)
{
	auto splash = load_resource(resource_path.append("/splash.txt"));
	// fg-color: green
	std::cout << '\n' << "\033[33m" << std::accumulate(splash.begin(), splash.end(), std::string("")) << "\033[0m" << '\n';
	std::cout << '\t';
	for (const auto& c : "ahvy sazl wny nrbbguz fo lvu oe davk sugpoj setkzdf")
	{
		std::cout << c;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	clear_screen();
}

void print_state(Game& hangman)
{
	std::string healthbar = std::string(hangman.life, '*');
	// pad with trailing whitespaces
	healthbar = healthbar.append(std::string(hangman.max_life - hangman.life, ' '));
	std::cout << '\n'
			  << '\t' << "Lifepoints: ["
			  << "\033[31m" << healthbar << "\033[0m" << ']' << '\n'; // fg-color: red
	std::cout << hangman.frames[hangman.frames.size() - 1 - hangman.life] << '\n';
	std::cout << '\t';
	for (auto& placeholder : hangman.guessed)
		std::cout << "\033[33m" << placeholder << "\033[0m ";
	std::cout << std::string(2, '\n');
}

void print_end_msg(Game& hangman)
{
	if (hangman.life == 0)
	{
		std::cout << "\033[31m";

		for (const auto& c : "you lost :(")
		{
			std::cout << c;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		std::cout << "\033[0m";
	}
	else
	{
		std::cout << "\033[33m";

		for (const auto& c : "you won :)")
		{
			std::cout << c;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		std::cout << "\033[0m";	
	}
}