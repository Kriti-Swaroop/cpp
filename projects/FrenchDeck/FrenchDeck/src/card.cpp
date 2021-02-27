#include <string>
#include "card.h"

class Card
{
public:
	Card(const int value, const Color color, const Suit suit)
	{
		this->value = value;
		this->color = color;
		this->suit = suit;
	}

	~Card()
	{

	}

#pragma region Accessors
	inline const int& get_value() const { return this->value; }

	inline const Color& get_color() const { return this->color; }

	inline const Suit& get_suit() const { return this->suit; }

	const std::string to_string()
	{
		return "Value: " + this->value;
	}
#pragma endregion

private:
	int value;
	Color color;
	Suit suit;
};
