#include <algorithm>
#include <random>
#include <vector>
#include "deck.hpp"
#include "utils.hpp"

/* There are 4*13=52 cards in a french deck of cards:
 * - 4 suites counting each 13 cards
 * - 2 colors (heart & tile = red, pike & clover = black)
 */

Deck::Deck()
{
	for (int suite = 0; suite <= 3; ++suite)
	{	
		int color = (suite % 2 == 0) ? 0 : 1;

		for (int value = 0; value <= 12; ++value)
		{
			this->cards.push_back(Card(value, color, suite));
		}
	}
}

void Deck::shuffle()
{
	std::random_device rd;
	std::default_random_engine rng(rd());
	std::shuffle(this->cards.begin(), this->cards.end(), rng);
}

Card Deck::draw()
{
	Card last_card = this->cards.back();
	this->cards.pop_back();
	return last_card;
}

void Deck::print()
{
	for (Card& card : this->cards)
		card.print();
}