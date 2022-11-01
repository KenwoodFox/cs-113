/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum Side
{
    Head,
    Tail,
};

/* I dont have a clue why this is failing zybooks unit test.
 */
string HeadsOrTails(Side side)
{
    switch (side)
    {
    case Head:
        return "heads";
        break;
    case Tail:
        return "tails";
        break;
    }
}

int main()
{
    // srand(time(NULL));
    srand(2);

    int _nFlips;
    scanf("%d", &_nFlips);

    for (uint8_t i = 0; i < _nFlips; i++)
    {
        int _face = rand() % 2;
        printf("%s\n", HeadsOrTails(_face == Head ? Head : Tail).c_str());
    }

    printf(MOTD); // Print build info
    return 0;
}
