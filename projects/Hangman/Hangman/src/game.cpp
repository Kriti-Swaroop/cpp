#include <fstream>
#include <filesystem>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

int random_range(const int& min, const int& max) {
	// in range of [min, max]
	static std::default_random_engine eng{ std::random_device{}() };
	std::uniform_int_distribution<int> dist(min, max);
	return dist(eng);
}

std::string random_choice(const std::vector<std::string>& vector)
{
	int random_index = random_range(0, vector.size() - 1);
	return vector[random_index];
}

std::vector<char> split_string(const std::string& to_split)
{
	std::vector<char> characters(to_split.begin(), to_split.end());
	return characters;
}

std::vector<std::string> load_resource(const std::string& path)
{
	std::string line{};
	std::vector<std::string> lines{};
	std::ifstream resource{ path };

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
	std::vector<char> characters{};
	int life{};
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
	hangman.word = random_choice(all_words);
	hangman.characters = split_string(hangman.word);
	hangman.life = hangman.frames.size();

	return hangman;
}