/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <string>

static const int automata_len = 30;
static const char alive = '1';
static const std::string aliveArt = "□"; // char16 encoding makes it hard to print on its own
static const char dead = '0';
static const std::string deadArt = "■";
char this_row[automata_len];
char next_row[automata_len];
int n_iters = 4; // Default to four iters

int main()
{
    printf("A cellular automata consists of cells and rows, when we advance a row we apply to it specific rules to compute its output.\n");
    printf("This program will iterate a cellular automata with the only rule being that a cell in a new row will be state %c (%s)\nif the state of the two cells above it (either side) is also %c. Much like the game of life)\n", alive, aliveArt.c_str(), alive);
    printf("Input a string of only %c or %c to represent black and white cells, the program will accept up to %d cells and will fill any trailing with %c.\n", alive, dead, automata_len, dead);

    printf("Input cells: ");
    for (int i = 0; i < automata_len; i++)
    {
        scanf("%c", &this_row[i]);
        if (this_row[i] == '\n')
        {
            this_row[i] = dead;
            break; // This is messy
        }
        else if (this_row[i] != alive && this_row[i] != dead) // Input cleaning
        {
            this_row[i] = dead;
        }
    }

    for (int i = 0; i < automata_len; i++)
    {
        printf("%s", this_row[i] == alive ? aliveArt.c_str() : deadArt.c_str());
    }

    printf("\nNumber of rows to iterate: ");
    scanf("%d", &n_iters);

    for (int i = 0; i < n_iters; i++)
    {
        for (int i = 0; i < automata_len; i++)
        {
            printf("%s", this_row[i] == alive ? aliveArt.c_str() : deadArt.c_str());

            // Warning! This may cause edgecases when overflowing!

            if (this_row[i - 1] != this_row[i]) // if match
            {
                next_row[i] = alive;
            }
            else
            {
                next_row[i] = dead;
            }
        }
        printf("\n");

        // Messy quick zipper merge
        for (int i = 0; i < automata_len; i++)
        {
            this_row[i] = next_row[i];
        }
    }

    printf(MOTD); // Print build info
    return 0;
}
