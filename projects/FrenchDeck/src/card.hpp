#pragma once
#include <array>

constexpr std::array<char, 13> VALUES = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'J', // jack
	'Q', // queen
	'K'  // king
};

constexpr std::array<char, 2> COLORS = { 
	'R', // red
	'B'  // black
};

constexpr std::array<char, 4> SUITES = {
	'C', // clover
	'H', // heart	
	'P', // pike
	'T'  // tile
};

struct Card
{
	char value;
	char color;
	char suite;

	Card(int value, int color, int suite);

	void print();
};
