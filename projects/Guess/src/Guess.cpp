/* PROJECT 1 - GUESS THE NUMBER
 * ----------------------------
 * In this game, the user enters a number which the computer has to guess by
 * using the divide and conquer strategy. How the turntables . . .
 */

#include <iostream>
#include <random>

int random_integer(int min, int max)
{
    // in range of [min, max]
    static std::default_random_engine eng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(min, max);
    return dist(eng);
}

void find_unknown_integer(int unknown, int min, int max, int guess)
{
    if (guess > unknown)
    {
        std::cout << "Guessed too high " << '(' << guess << ')' << '\n';
        int new_guess{ (min + guess) / 2 };
        find_unknown_integer(unknown, min, guess - 1, new_guess);
    }
    else if (guess < unknown)
    {
        std::cout << "Guessed too low " << '(' << guess << ')' << '\n';
        int new_guess{ (guess + max) / 2 };
        find_unknown_integer(unknown, guess + 1, max, new_guess);
    }
    else
    {
        std::cout << "Guessed correctly: " << guess << '\n';
    }
}

int main()
{
    int unknown{};
    int min = 0;
    int max = 100;

    std::cout << "Enter an integer between " << min << " and " << max << ": ";
    std::cin >> unknown;
    
    find_unknown_integer(unknown, min, max, random_integer(min, max));
    return 0;
}
