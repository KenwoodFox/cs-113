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

struct Player
{
    int score = 0;        // Their score
    Card hand[5];         // Hold up to 5 cards
    int player_idx = 0;   // The last blank handslot
    bool staying = false; // True when they are staying
};

int main()
{
    // Rand seed
    std::srand(std::time(nullptr));

    // Create (and shuffle) a deck
    Deck dealerDeck = Deck();

    // Some memory and stats
    int n_players, n_rounds, card_idx = 0, hand_sum, _in;

    printf("You are playing blackjack, the goal of the game is to get as close to 21 as possible without going over.\n");
    printf("How many players in this game? (works best with 5 or less)\n");
    scanf("%d", &n_players);
    Player players[n_players];

    printf("How many rounds in this game? (works best with 3)\n");
    scanf("%d", &n_rounds);

    for (int round = 0; round < n_rounds; round++)
    {
        // Scoreboard
        printf("\n\n");
        for (int p_score_i = 0; p_score_i < n_players; p_score_i++)
        {
            printf("Player %d Score: %d, ", p_score_i + 1, players[p_score_i].score);
        }
        printf("\n\n");

        // Player's turn
        for (int c_player = 0; c_player < n_players; c_player++)
        {
            printf("It is player %d's turn. Your hand is as follows:\n", c_player + 1);
            hand_sum = 0;
            for (int j = 0; j < 5; j++)
            {
                if (players[c_player].hand[j].value != -1)
                { // Check if this particular card in their hand is populated
                    hand_sum += players[c_player].hand[j].value + 1;
                    players[c_player].hand[j].show();
                }
            }
            printf("Sum of hand: %d.\n", hand_sum);

            printf("You may either:\n [0] Hit\n [1] Stand\n");
            scanf("%d", &_in);
            if (_in == 0)
            {
                players[c_player].hand[players[c_player].player_idx] = dealerDeck.cards[card_idx];
                dealerDeck.cards[card_idx].show();
                players[c_player].score = hand_sum + dealerDeck.cards[card_idx].value + 1;
                printf("Your score is now %d\n", players[c_player].score);
                card_idx++;
                players[c_player].player_idx++;
            }
            else
            {
                printf("Player %d stands.\n\n", c_player);
            }
        }
    }

    printf(MOTD); // Print build info
    return 0;
}
