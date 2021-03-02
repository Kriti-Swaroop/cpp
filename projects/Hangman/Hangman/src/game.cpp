#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void test()
{
	std::cout << "\033[93mHello World!\033[0m\n";
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
			lines.push_back(line);
		}
	}
	else
	{
		std::cerr << "File not found: " << path << '\n';
	}

	return lines;
}

std::string join_vector(const std::vector<std::string>& vector)
{
	std::string joined{};

	for (auto &line : vector)
	{
		joined += (line + '\n');
	}

	return joined;
}