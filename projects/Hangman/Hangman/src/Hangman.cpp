/* PROJECT 4 - Hangman
 * -------------------
 * ...
 */

#include <iostream>
#include "game.hpp"

int main()
{
	get_user_input<int>("Enter a number: ");
	
	auto txt6 = load_resource("./resources/9.txt");
	std::cout << join_vector(txt6);

	std::cin.get();
}
