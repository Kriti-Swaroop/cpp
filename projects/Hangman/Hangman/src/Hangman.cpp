/* PROJECT 4 - Hangman
 * -------------------
 * ...
 */

#include <iostream>
#include <string>
#include "game.hpp"
#include "utils.hpp"

int main()
{
	std::string resource_path = "./resources";
	auto hangman = setup(resource_path);
	hangman.life = 6;
	print_splash_screen(resource_path);

	print_state(hangman);
	auto letter = get_user_input<char>("\t>>> ");

	std::cin.get();
}
