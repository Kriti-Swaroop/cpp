/* PROJECT 4 - Hangman
 * -------------------
 * ...
 */

#include <iostream>
#include "game.hpp"

int main()
{
	// test setup procedure
	get_user_input<int>("Enter a number: ");
	
	auto hangman = setup("resources");
	std::cout << hangman.word << '\n';

	std::cin.get();
}
