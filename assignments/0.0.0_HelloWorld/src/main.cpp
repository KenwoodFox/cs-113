/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD "?"
#endif

#include <iostream>

#include "printhello.h"

int main()
{
    printHello();

    std::cout << MOTD; // Print build info
    return 0;
}
