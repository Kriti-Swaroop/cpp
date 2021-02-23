/* PROJECT 1 - GUESS THE NUMBER
 * ----------------------------
 * In this game, the user enters a number which the computer has to guess by
 * using the divide and conquer strategy. How the turntables . . .
 */

#include <iostream>
#include <time.h>

int getRandomInteger(int min, int max)
{
    // randomInteger ¸ [min, max]
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

void findUnknownInteger(int unknown, int min, int max, int guess)
{
    if (guess > unknown)
    {
        std::cout << "Guessed too high " << '(' << guess << ')' << '\n';
        int newGuess{ (min + guess) / 2 };
        findUnknownInteger(unknown, min, guess - 1, newGuess);
    }
    else if (guess < unknown)
    {
        std::cout << "Guessed too low " << '(' << guess << ')' << '\n';
        int newGuess{ (guess + max) / 2 };
        findUnknownInteger(unknown, guess + 1, max, newGuess);
    }
    else
    {
        std::cout << "Guessed correctly: " << guess << '\n';
    }
}

int main()
{
    int unknown;
    int min = 0;
    int max = 100;

    std::cout << "Enter an integer between " << min << " and " << max << ": ";
    std::cin >> unknown;
    
    // enter the game
    int initialGuess = getRandomInteger(min, max);
    findUnknownInteger(unknown, min, max, initialGuess);
    return 0;
}
