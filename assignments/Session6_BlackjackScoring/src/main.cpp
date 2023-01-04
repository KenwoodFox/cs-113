/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <ctime>

#include "cards.h"

void drawCard(Card (&hand)[52], Deck deck, int &idx, int &sum, bool &ace);

/* This is a stripped down version of the full
 * blackjack program from last week.
 */
int main()
{
    // For user
    int _in = 0;

    do
    {
        // Rand seed
        std::srand(std::time(nullptr));

        // Create (and shuffle) a deck
        Deck dealerDeck = Deck();

        // Hand and game setup
        int deckIdx = 0, sum = 0;
        bool ace = false;
        Card hand[52];

        printf("You are playing simplified blackjack, the goal is to get as close to 21 as you can.\nYour current hand is:\n");
        for (uint8_t i = 0; i < 2; i++) // Inital cards
        {
            drawCard(hand, dealerDeck, deckIdx, sum, ace);
        }
        printf("Total Value %d, %d away from 21.\n", sum, 21 - sum);

        do
        {
            printf("\nWould you like to draw a card?\n [0] Stay\n [1] Hit\n");
            scanf("%d", &_in);
            if (_in == 1)
            {
                drawCard(hand, dealerDeck, deckIdx, sum, ace);
                printf("Your current hand is:\n");
                for (uint8_t i = 0; i < deckIdx; i++)
                {
                    hand[i].show();
                }

                // Check if you go over
                if (sum > 21)
                {
                    if (ace == true) // save me!
                    {
                        sum = sum - 9;
                    }
                    if (sum > 21)
                    {
                        break; // For real now!
                    }
                }
                printf("Total Value %d, %d away from 21.\n", sum, 21 - sum);
            }
        } while (_in != 0);

        // Lets see the score!
        int computer = rand() % 21;
        printf("The computer had a hand of %d, while you had a hand of %d. You %s\n", computer, sum, sum > 21 ? "went over 21 and lost!" : sum > computer ? "beat the computer with a higher score!"
                                                                                                                                                          : "Lost to the computer, your score was lower!");
        printf("Play again?\n [0] No\n [1] Yes\n");
        scanf("%d", &_in);

    } while (_in != 0);

    printf(MOTD); // Print build info
    return 0;
}

void drawCard(Card (&hand)[52], Deck deck, int &idx, int &sum, bool &ace)
{
    hand[idx] = deck.cards[idx];   // Get the card from the dealer
    ace = hand[idx].value == 0;    // Check if its ace
    sum += hand[idx].getGameVal(); // Get its legal value
    hand[idx].show();              // Show it
    idx++;                         // Next card
}
