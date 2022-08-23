/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

#define startTime 2
#define parkingDuration 4

char bodyChar, tipChar;

void printArrow(char bodyChar, char tipChar, uint8_t bodyLength = 5, uint8_t tipLength = 4, uint8_t bodyHeight = 3, uint8_t tipHeight = 7);
void printWhiteChar(bool eval, char ifChar, char whiteChar = ' ');

int main()
{
    // Load in values
    // std::cin >> bodyChar;
    // std::cin >> tipChar;
    bodyChar = '0';
    tipChar = '1';

    printArrow(bodyChar, tipChar);

    std::cout << MOTD; // Print build info
    return 0;
}

void printArrow(char bodyChar, char tipChar, uint8_t bodyLength, uint8_t tipLength, uint8_t bodyHeight, uint8_t tipHeight)
{
    for (uint8_t row = 0; row < tipHeight; row++)
    {
        for (uint8_t col = 0; col < bodyLength + tipLength; col++)
        {
            // Draw body
            if (col < bodyLength)
            {
                printWhiteChar(bodyHeight >= (abs(row - (tipHeight / 2))) * 3, bodyChar);
            }
            // Draw tip
            else
            {
                printWhiteChar(col - bodyLength + 1 > abs(row - (tipHeight / 2)), tipChar, '\0');
            }
        }
        std::cout << "\n";
    }
}

void printWhiteChar(bool eval, char ifChar, char whiteChar)
{
    if (eval)
    {
        std::cout << ifChar;
    }
    else
    {
        std::cout << whiteChar;
    }
}