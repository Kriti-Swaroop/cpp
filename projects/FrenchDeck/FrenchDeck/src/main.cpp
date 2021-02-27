/* PROJECT 3 - French Deck of Cards
 * --------------------------------
 * Implements a (french-)deck of cards with a total of 52 cards. 
 */

#include <iostream>
#include "card.h"

int main()
{
    Card test_card = Card::Card(1, Color::Red, Suit::Heart);
    std::cout << test_card.to_string() << '\n';
    std::cout << static_cast<int>(Color::Black) << '\n';
    return 0;
}
