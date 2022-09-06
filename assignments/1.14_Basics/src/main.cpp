/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

int16_t base;

int main()
{
    std::cin >> base;

    std::cout << base * base << "\n";

    std::cout << MOTD; // Print build info
    return 0;
}
