/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

enum players
{
    PLAYER,
    COMPUTER
};

int main()
{
    int n_marbles = 23;
    printf("You are playing the game of 23,\nyou will go first and be asked to\nwithdraw 1, 2 or 3 marbles.\nThe goal is avoid taking the last marble.\nGood luck!\n\n");

    int userSel, turn;
    while (true)
    {
        /*
         * Player's turn
         */
        turn = PLAYER;
        printf("\nIt is your turn, there are \x1B[31m%d\x1B[0m marbles remaining.\n", n_marbles);

        do // TODO: change me
        {
            printf("You may remove %s\n", n_marbles > 3 ? "1 2 or 3 marbles" : n_marbles > 2 ? "1 or 2 marbles"
                                                                                             : "1 marble");
            printf("Enter a number ");
            scanf("%d", &userSel);
        } while (!(userSel >= 1 && userSel <= 3 && userSel <= n_marbles));

        // Input is sanitized (maybe) remove marbles
        n_marbles = n_marbles - userSel;
        if (n_marbles <= 0)
        {
            break;
        }

        /*
         * Computers turn
         */
        turn = COMPUTER;
        printf("\nIt is the computer's turn, there are \x1B[31m%d\x1B[0m marbles remaining.\n", n_marbles);
        int computerAction = n_marbles > 4 ? 4 - userSel : (n_marbles >= 2 && n_marbles <= 4) ? n_marbles - 1
                                                                                              : 1;

        n_marbles = n_marbles - computerAction;
        if (n_marbles <= 0)
        {
            break;
        }
        printf("The computer removed \x1B[33m%d\x1B[0m marble%s.\n", computerAction, computerAction > 1 ? "s" : "");
    }

    if (turn == PLAYER)
    {
        printf("\n\x1B[31mYou lost!\x1B[0m The computer forced you to take the last amarble,\nbetter luck next time!\n");
    }
    else
    {
        printf("\n\n\x1B[36mYou win!\x1B[0m You forced the computer to take the last marble.");
    }

    printf(MOTD); // Print build info
    return 0;
}
