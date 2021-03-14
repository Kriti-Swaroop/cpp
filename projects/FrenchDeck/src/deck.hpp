#pragma once
#include <vector>
#include "card.hpp"


struct Deck
{
	std::vector<Card> cards{};
	Deck();
	void shuffle();
	void draw();
	void print();
};