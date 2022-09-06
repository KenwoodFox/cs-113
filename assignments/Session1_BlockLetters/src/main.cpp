/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string.h>
#include <bigLetters.h>

void getCharmap();
void printBigChars(const std::string &s);

int main()
{
    // Setup charmap (messy but this whole thing is messy)
    getCharmap();

    printBigChars("JOE SEDUTTO");

    std::cout << MOTD; // Print build info
    return 0;
}

// Charmap, maps ascii values to char ones.
void getCharmap()
{
    charMap[74] = 0; // J
    charMap[79] = 1; // O
    charMap[69] = 2; // E
    charMap[32] = 3; //
    charMap[83] = 4; // S
    charMap[68] = 5; // D
    charMap[85] = 6; // U
    charMap[84] = 7; // T
}

/* Supports up to 20 input chars
 */
void printBigChars(const std::string &s)
{
    for (uint8_t row = 0; row < 8; row++) // const 8, replace later
    {
        for (std::string::size_type col = 0; col < s.size(); col++)
        {
            std::cout << bigLetters[charMap[int(s[col])]].lines[row];
        }
        std::cout << ("\n");
    }
}
