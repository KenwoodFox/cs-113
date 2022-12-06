/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// TODO: Finish eval function, this game must be absolutly unbeatable!

class Board
{
public:
    static const int FSIZE = 3;
    int field[FSIZE][FSIZE] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}; // A square playing field.

    /* Prints out a nice graphic for a tic-tac-toe field
     *
     * @returns Nothing
     */
    void printField()
    {
        printf("/-----\\\n");
        for (uint8_t y = 0; y < FSIZE; y++)
        {
            for (uint8_t x = 0; x < FSIZE; x++)
            {
                printf("|%s", field[x][y] == 0 ? "O" : field[x][y] == 1 ? "X"
                                                                        : " ");
            }
            printf("|\n");
        }
        printf("\\-----/\n");
    }

    /* Mark a spot on the map
     *
     * @returns if spot is valid
     */
    bool mark(int x, int y, int mark = 1)
    {
        if (x > FSIZE || y > FSIZE || x < 0 || y < 0)
        {
            return false; // Out of bounds
        }

        if (field[x][y] == -1)
        {
            field[x][y] = mark;
            return true;
        }

        return false;
    }

    // Should be a min/maximizer in here
    int minmax(int depth = 10, bool isMax)
    {
        int score = evaluate();
    }

    /* Asks the computer to make a move
     * @returns false if the computer gives up
     */
    bool makeMove()
    {
        for (uint8_t y = 0; y < FSIZE; y++)
        {
            for (uint8_t x = 0; x < FSIZE; x++)
            {
            }
        }
        return false;
    }

    /* @returns true if won
     */
    int evaulate(int delim = 0)
    {
        int seqRow = 0;
        int seqCol = 0;
        int score = 0;

        // Check for simple win via rows
        for (uint8_t y = 0; y < FSIZE; y++)
        {
            for (uint8_t x = 0; x < FSIZE; x++)
            {
                if (field[x][y] == delim)
                {
                    seqRow++;
                }
                else
                {
                    seqRow = 0;
                }
                if (field[y][x] == delim)
                {
                    seqCol++;
                }
                else
                {
                    seqCol = 0;
                }
            }
            if (seqRow >= 3 || seqCol >= 3)
            {
                score += 10;
            }
        }
        return false;
    }
};

int main()
{
    int sel = 0;
    int markx, marky;
    Board myBoard = Board();

    printf("You are playing tic tac toe, ");
    do
    {
        printf("select what player will go first:\n [0] Human\n [1] Computer\n");
        scanf("%d", &sel);
    } while (sel != 0 && sel != 1);

    if (sel == 1)
    {
    }

    myBoard.printField();

    while (!myBoard.isWon() && !myBoard.isWon(1))
    {
        do
        {
            printf("It is your turn, enter a valid spot to mark: ");
            scanf("%d", &markx);
            scanf("%d", &marky);
        } while (!myBoard.mark(markx - 1, marky - 1));
        myBoard.printField();
    }
    printf("%d", myBoard.isWon(0));
    printf("%d", myBoard.isWon(1));

    printf(MOTD); // Print build info
    return 0;
}
