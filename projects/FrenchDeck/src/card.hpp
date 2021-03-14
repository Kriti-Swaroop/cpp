#pragma once
#include <map>

const std::map<int, char> VALUES = {
	{1, '1'},
	{2, '2'},
	{3, '3'},
	{4, '4'},
	{5, '5'},
	{6, '6'},
	{7, '7'},
	{8, '8'},
	{9, '9'},
	{10, 'T'}, // ten
	{11, 'J'}, // jack
	{12, 'Q'}, // queen
	{13, 'K'}, // king
};

const std::map<int, char> COLORS = {
	{1, 'R'},
	{2, 'B'}
};

const std::map<int, char> SUITES = {
	{1, 'H'}, // heart
	{2, 'T'}, // tile
	{3, 'C'}, // clover
	{4, 'P'}  // pike
};

struct Card
{
	char value;
	char color;
	char suite;

	Card(int value, int color, int suite);

	void print();
};
