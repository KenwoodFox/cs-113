/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <cmath>
#include <algorithm>

// Uses the minmax method of keeping you from winning

// Movement on the board
struct Move
{
    int row, col;
};

char player = 'X', com = 'O', nomove = '_';
bool moveFirst = false;

// The board itself, (_) denotes no play
char board[3][3] =
    {
        {nomove, nomove, nomove},
        {nomove, nomove, nomove},
        {nomove, nomove, nomove}};

/* True if game is over. */
bool gameOver(char b[3][3]);

/* Part of the minmax, basically tells us our score. */
int evaluate(char b[3][3]);

/* Like a chess solver (but smaller) tests and evaulates each move on the board. */
int minimax(char b[3][3], int depth, bool isCom);

/* Actually compute the best move (wikipedia, and again, like chess) */
Move computeBest(char b[3][3]);

// Draw the board
void drawBoard(char b[3][3]);

// Make a move
int makeMove(char b[3][3], Move move, char player = com);

int main()
{
    printf("You are playing tic tac toe! Do you go first?\n[Y/n] ");
    char _inp;
    scanf("%c", &_inp);
    moveFirst = _inp == 'n' ? false : true; // Select move first or not

    Move playerMove;

    if (moveFirst)
    {
        drawBoard(board);
        printf("You're playing first, make your move!\n(row, col): ");
        scanf("%d", &playerMove.row);
        scanf("%d", &playerMove.col);
        makeMove(board, playerMove, player);
    }
    else
    {
        printf("The computer plays first:\n");
    }

    while (!gameOver(board))
    {
        // Computer turn
        drawBoard(board);
        Move bestMove = computeBest(board);
        makeMove(board, bestMove);
        drawBoard(board);

        if (abs(evaluate(board)) >= 10)
        {
            break;
        }

        // Player turn
        do
        {
            printf("\nIts your turn, make your move!\n(row, col): ");
            scanf("%d", &playerMove.row);
            scanf("%d", &playerMove.col);
        } while (makeMove(board, playerMove, player) != 0);

        if (abs(evaluate(board)) >= 10)
        {
            break;
        }
    }

    printf("You %s!\n", evaluate(board) == -10 ? "won! Congrats" : "lost to the computer");

    printf(MOTD); // Print build info
    return 0;
}

void drawBoard(char b[3][3])
{
    printf("| 0 | 1 | 2 |\n");
    for (int row = 0; row < 3; row++)
    {
        printf("| %c | %c | %c |\n", b[row][0], b[row][1], b[row][2]);
    }
    printf("| 0 | 1 | 2 |\n\n");
}

int makeMove(char b[3][3], Move move, char player)
{
    if (b[move.row][move.col] != nomove)
    {
        return 1; // Nope!
    }
    b[move.row][move.col] = player;
    return 0;
}

Move computeBest(char b[3][3])
{
    int bestScore = -1000;
    Move bestMove; // Empty move
    bestMove.row = -1;
    bestMove.col = -1;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (b[row][col] == nomove)
            {
                // This spot is empty, lets test it!
                b[row][col] = player;
                int moveScore = minimax(b, 0, false);
                b[row][col] = nomove;

                // Is it better?
                if (moveScore > bestScore)
                {
                    bestMove.row = row;
                    bestMove.col = col;
                }
            }
        }
    }
    return bestMove;
}

bool gameOver(char b[3][3])
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (b[row][row] == nomove)
            {
                return false; // Once we find _any_ possible move, we're not done
            }
    return true;
}

int minimax(char b[3][3], int depth, bool isCom = true)
{
    int currentState = evaluate(b);

    // Has somebody already won the game?
    if (abs(currentState) >= 10)
    {
        return currentState;
    }

    // Are there moves left to make?
    if (gameOver(b))
    {
        return 0; // All is lost!
    }

    // Implementation of wikipedia minmax recursion algo
    if (isCom)
    {
        int best = -1000;

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                // If not empty
                if (b[row][col] == nomove)
                {
                    b[row][col] = player;
                    best = std::max(best, minimax(b, depth + 1, !isCom));
                    b[row][col] = nomove; // Undo
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                // If not empty
                if (b[row][col] == nomove)
                {
                    b[row][col] = com;
                    best = std::max(best, minimax(b, depth + 1, !isCom));
                    b[row][col] = nomove; // Undo
                }
            }
        }
        return best;
    }
}

int evaluate(char b[3][3])
{
    // Check for victory conditions (rows, cols, diags)
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2])
        { // if all in a row
            if (b[row][0] == player)
            {
                return -10; // Dont let the player win!
            }
            else if (b[row][0] == com)
            {
                return 10; // Play this move!
            }              // If its not these two, then the row is empty
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col])
        { // if all in a col
            if (b[0][col] == player)
            {
                return -10; // Dont let the player win!
            }
            else if (b[0][col] == com)
            {
                return 10; // Play this move!
            }              // If its not these two, then the col is empty
        }
    }

    // Diags
    if ((b[0][0] == b[1][1] && b[1][1] == b[2][2]) || (b[0][2] == b[1][1] && b[1][1] == b[2][0]))
    {
        return b[1][1] == player ? -10 : b[1][1] == com ? 10
                                                        : 0;
    }

    // If nothing significant, then nothing significant.
    return 0;
}
