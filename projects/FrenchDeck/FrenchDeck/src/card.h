#pragma once

enum class Suit : unsigned char
{
	Heart,
	Tile,
	Clover,
	Pike
};

enum class Color : unsigned char
{
	Red,
	Black
};

class Card
{
private:
	int value;
	Color color;
	Suit suit;

public:
	Card(const int value, const Color color, const Suit suit);
	~Card() { }
	inline const int& get_value() const;
	inline const Color& get_color() const;
	inline const Suit& get_suit() const;
	const std::string to_string();
};

