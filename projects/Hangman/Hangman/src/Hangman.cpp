/* PROJECT 4 - Hangman
 * -------------------
 * ...
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"
#include "utils.hpp"

int main()
{
	std::string resource_path = "./resources";
	auto hangman = setup(resource_path);
	print_splash_screen(resource_path);

	bool playing = hangman.life > 0;

	while (playing)
	{
		print_state(hangman);
		auto input = get_user_input<char>("\t>>> ");
		bool hit = false;

		for (std::size_t i = 0; i < hangman.letters.size(); ++i)
		{
			if (input == hangman.letters[i])
			{
				hangman.guessed[i] = input;
				hit = true;
			}
		}

		if (!hit)
		{
			--hangman.life;
		}

		clear_screen();

		bool won = std::all_of(hangman.guessed.begin(), hangman.guessed.end(), [&](const char& el) { return el != '_'; });

		if (hangman.life == 0 || won)
		{
			playing = false;
		}
	}

	print_end_msg(hangman);

	std::cin.get();
}
