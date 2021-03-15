#include <iostream>
#include <string>
#include "card.hpp"

Card::Card(int value, int color, int suite)
{
	this->value = VALUES[value];
	this->color = COLORS[color];
	this->suite = SUITES[suite];
}

void Card::print()
{
	std::string tmp{};
	std::string red = this->color == 'R' ? "\033[31m" : "";
	std::string& ten_or_lower = isdigit(this->value) ? std::to_string((int)(this->value) + 1 - 48) : tmp.assign(1, this->value);
	std::cout << red << "Value:\t" << ten_or_lower << "\tColor:\t" << this->color << "\tSuite:\t" << this->suite << "\033[0m" << '\n';
}