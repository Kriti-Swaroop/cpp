/* PROJECT 4 - Hangman
 * -------------------
 * ...
 */

#include <iostream>
#include "game.hpp"
#include "utils.hpp"

int main()
{
	auto hangman = setup("./resources");
	print_state(hangman);
	auto letter = get_user_input<char>("Enter a letter: ");

	std::cin.get();
}
