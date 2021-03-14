#include <iostream>
#include <string>
#include "card.hpp"

Card::Card(int value, int color, int suite)
{
	this->value = VALUES.at(value);
	this->color = COLORS.at(color);
	this->suite = SUITES.at(suite);
}

void Card::print()
{
	std::string red = this->color == 'R' ? "\033[31m" : "";
	std::cout << red << "Value:\t" << this->value << "\tColor:\t" << this->color << "\tSuite:\t" << this->suite << "\033[0m" << '\n';
}