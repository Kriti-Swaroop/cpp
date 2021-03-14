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
	for (int suite = 1; suite <= 4; ++suite)
	{	
		int color = (suite % 2 == 0) ? 1 : 2;

		for (int value = 1; value <= 13; ++value)
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

void Deck::draw()
{
	Card draw_card = random_choice<Card>(this->cards);
	draw_card.print();
}

void Deck::print()
{
	for (Card card : this->cards)
		card.print();
}