#include <cmath>
#include <iostream>

constexpr double GRAVITY{ 9.8 };

double calculate_height(double height, int seconds)
{
	// s = u * t + (a + t^2) / 2 (here: u=0)
	double distance{ GRAVITY * (std::pow(seconds, 2)) / 2.0 };
	return { height - distance };
}

void print_status(double height, int seconds)
{
	if (height > 0)
		std::cout << "At " << seconds << " seconds, the apple is at height " << height << " meters." << '\n';
	else
		std::cout << "The apple hit the ground at " << seconds << " seconds." << '\n';
}

int main()
{
	int current_second{ 0 };
	double tree_height{ 100 };
	double current_height{ };

	while (current_height >= 0)
	{
		current_height = calculate_height(tree_height, current_second);
		print_status(current_height, current_second);
		++current_second;
	}

	std::cin.get();
}