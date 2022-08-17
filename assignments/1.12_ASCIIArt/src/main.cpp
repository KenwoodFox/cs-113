/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

// Choose what art we want to display
#define ART_SEL 1
// Only valid for ART_SEL != 0
#define TREE_SIZE 7

#include <iostream>
#include <string>

const static char catArt[] = "/\\   /\\\n  o o\n =   =\n  ---\n";

void printBranch(uint8_t row);

int main()
{

    // Tree mode
    for (uint8_t row = 0; row < (TREE_SIZE / 2) + 1; row++)
    {
        printBranch(row);
    }

    // Regenerates the foot
    printBranch(1);
    if (ART_SEL > 0)
    {
        // Print cat
        std::cout << "\n\n";
        std::cout << catArt;
    }

    std::cout << MOTD; // Print build info
    return 0;
}

void printBranch(uint8_t row)
{
    for (uint8_t col = 0; col < TREE_SIZE; col++)
    {
        if (row + 1 > abs(col - (TREE_SIZE / 2)))
        {
            std::cout << "*";
        }
        else if (col - (TREE_SIZE / 2) < 0)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}
