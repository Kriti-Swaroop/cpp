/* PROJECT 3 - French Deck of Cards
 * --------------------------------
 * Implements a french deck of cards with a total of 52 cards. 
 */

#include <iostream>
#include <string>
#include "card.hpp"
#include "deck.hpp"

int main()
{
    Deck fd = Deck();

    std::cout << '\n' << "Sorted Deck:" << '\n';
    std::cout << std::string(41, '-') << '\n';
    fd.print();

    std::cout << '\n' << "Shuffled Deck:" << '\n';
    std::cout << std::string(41, '-') << '\n';
    fd.shuffle();
    fd.print();

    std::cout << '\n' << "You drawed:" << '\n';
    std::cout << std::string(41, '-') << '\n';
    fd.draw();

    std::cin.get();
    return 0;
}
