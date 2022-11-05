/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <ctime>

#include "cards.h"

int main()
{
    // Rand seed
    std::srand(std::time(nullptr));

    // Create (and shuffle) a deck
    Deck myDeck = Deck();

    const int MAX_HANDS = 4, MAX_CARDS = 14;
    int hands = 0, cardsPerHand = 0;

    // Inputs
    do
    {
        printf("Enter the number of cards per hand (<=%d)\n", MAX_CARDS);
        scanf("%d", &cardsPerHand);
    } while (cardsPerHand < 0 || cardsPerHand > MAX_CARDS);

    do
    {
        printf("Enter the number of hands/players (<=%d)\n", MAX_HANDS);
        scanf("%d", &hands);
    } while (hands < 0 || hands > MAX_HANDS);

    // Show some cards!
    int j = 0;
    for (uint8_t i = 0; i < hands; i++)
    {
        printf("\nHand %d/%d\n---------------------\n", i + 1, hands);

        for (uint8_t _j = 0; _j < cardsPerHand; _j++) // _j never used
        {
            myDeck.cards[_j + j].show();
            j++;
        }
    }

    printf(MOTD); // Print build info
    return 0;
}
