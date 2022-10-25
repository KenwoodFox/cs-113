/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <time.h>

enum Games
{
    HandGame,
    DieRoll,
    NumberGuess,
    ReverseNumberGuess
};

enum Hands
{
    Rock,
    Paper,
    Scissors
};

void printDie(int face)
{
    printf("/---\\\n");
    printf("|%s|\n", face == 2 || face == 3 ? "*  " : face == 4 || face == 5 || face == 6 ? "* *"
                                                                                          : "   ");
    printf("|%s|\n", face == 1 || face == 5 || face == 3 ? " * " : "   ");
    printf("|%s|\n", face == 4 || face == 5 || face == 6 ? "* *" : face == 2 || face == 3 ? "  *"
                                                                                          : "   ");
    printf("\\---/\n");
}

int main()
{
    // Init rand
    srand(time(NULL));

    printf("Select a game\n");
    printf(" Hand Game\t\t[%d]\n Die roll\t\t[%d]\n Number Guess\t\t[%d]\n Reverse Number Guess\t[%d]\n", HandGame, DieRoll, NumberGuess, ReverseNumberGuess);

    int _sel = 0;
    scanf("%d", &_sel);

    // Hand Game
    int n_games = 100;
    int hands[3];
    int p1Wins = 0, p2Wins = 0, draws = 0;

    // Dice
    int dice[6];

    // Guessing game
    int _secret = 0;
    int _guess = 0;

    // Reverse guessing
    int n_iters = 0;

    switch (_sel)
    {
    case HandGame:

        for (int i = 0; i < 100; i++)
        {
            int _p1 = rand() % 3;
            int _p2 = rand() % 3;

            hands[_p1]++;
            hands[_p2]++;

            if (_p1 != _p2)
            {
                if (_p1 - 1 == _p2 || _p1 == Rock && _p2 == Scissors) // Cyclic
                {
                    p1Wins++;
                }
                else
                {
                    p2Wins++;
                }
            }
            else
            {
                draws++;
            }
        }

        printf("After %d simulated games, p1 won %d and p2 won %d, with %d draws.\n", n_games, p1Wins, p2Wins, draws);
        printf(" Rock\t\t%d\n Paper\t\t%d\n Scissors\t%d\n", hands[Rock], hands[Paper], hands[Scissors]);
        break;

    case DieRoll:
        for (int i = 0; i < n_games; i++)
        {
            int _roll = rand() % 6 + 1;
            dice[_roll - 1]++;
            printDie(_roll);
        }

        printf("After %d simulated games, here were the dice breakdowns:\n", n_games);
        for (int i = 0; i < 6; i++)
        {
            printf(" Face %d: %d times\n", i + 1, dice[i]);
        }
        break;

    case NumberGuess:
        _secret = rand() % n_games + 1;

        printf("The computer has chosen a random number between 1 and %d, place an inital guess now: ", n_games);
        scanf("%d", &_guess);
        while (_guess != _secret && _guess != -1)
        {
            printf("Your guess was %s than the secret number, type -1 at any time to give up.\n", _guess > _secret ? "larger" : "smaller");
            printf("Guess again: ");
            scanf("%d", &_guess);
        }
        printf("You %s, the secret number was %d.\n", _guess == _secret ? "won" : "lost", _secret);
        break;

    case ReverseNumberGuess:
        printf("The computer will try and guess your number in the fewest moves possible.\n");
        printf("Please enter a number between 1 and %d: ", n_games);
        do
        {
            scanf("%d", &_secret);
        } while (_secret >= n_games || _secret <= 1);

        _guess = n_games / 2; // inital guess
        while (_guess != _secret)
        {
            printf("The computer guesses %d\n", _guess);
            n_iters++;
            if (_guess > _secret)
            {
                _guess = _guess / 2;
            }
            else
            {
                _guess = _guess + (_guess / 2);
            }
        }

        printf("The computer found your secret number to be %d, finding it in %d moves!\n", _guess, n_iters);
        break;

    default:
        std::cerr << "Bad input!\n";
        break;
    }

    printf(MOTD); // Print build info
    return 0;
}
