/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <algorithm>
#include <stdint.h>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <unistd.h>

static const uint8_t MAX_DICT = 10;

int main()
{
    // No buffering
    setbuf(stdout, NULL);
    // Our wordfile
    std::ifstream wordFile;
    wordFile.open("words.txt");

    // Init rand
    srand(time(NULL));
    int gameArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // All the words in the game
    std::random_shuffle(gameArr, gameArr + 9);

    // An array of string objects
    std::string wordDict[MAX_DICT]; // Up to 10 objects

    printf("Loading words");
    for (uint8_t i = 0; i < MAX_DICT; i++)
    {
        printf(".");
        std::getline(wordFile, wordDict[i]); // stick it in there
        sleep(1);
    }
    wordFile.close();
    printf("Done\n\n\n");

    printf("You are playing Word Jumble! Follow the prompts below to play.\n");

    int sel = -1;
    int idx = 0;

    while (sel != 0)
    {
        if (idx > 9)
        {
            printf("\nYou completed all of the words in this game, congrats!!!\n");
            break;
        }

        std::string origWord = wordDict[gameArr[idx]];          // Pick a word
        std::string shuffleWord = origWord;                     // Copy it
        char guessWord[101];                                    // User guess can be at most, 100 chars long
        random_shuffle(shuffleWord.begin(), shuffleWord.end()); // Shuffle it up!

        printf("Your word is: %s\nStart Guessing!\n", shuffleWord.c_str());
        int tries = 1; // Number of guesses
        while (sel != 0)
        {
            printf("Guess: ");
            scanf("%100s", guessWord);
            if (guessWord[0] == '0') // Quit on 0
            {
                sel = 0;
                break;
            }

            // Iterate the player's guess
            int idx = 0;
            bool win = true;
            for (auto &ch : origWord)
            {
                printf("%c", tolower(ch) == tolower(guessWord[idx]) ? ch : '-');
                if (tolower(ch) == tolower(guessWord[idx]) && win)
                {
                    win = true;
                }
                else
                {
                    win = false;
                }
                idx++;
            }

            if (win)
            {
                printf("\nYou won! The word was %s. You guessed it in %d tries.\n", origWord.c_str(), tries);
                idx++;
                tries = 0;
                break;
            }
            else
            {
                printf("\nWrong guess, try again or enter 0 to quit. Your word is %s\n", shuffleWord.c_str());
                tries++;
            }
        }
        idx++;
    }

    printf(MOTD); // Print build info
    return 0;
}
