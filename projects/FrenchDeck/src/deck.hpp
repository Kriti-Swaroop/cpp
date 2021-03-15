#pragma once
#include <vector>
#include "card.hpp"


struct Deck
{
	std::vector<Card> cards{};
	Deck();
	void shuffle();
	Card draw();
	void print();
};