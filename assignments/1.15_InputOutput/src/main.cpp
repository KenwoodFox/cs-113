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
    // Prompt for a number
    std::cout << "Enter x: \n";
    std::cin >> base;

    std::cout << "x doubled is: " << base * 2 << "\n";

    std::cout << MOTD; // Print build info
    return 0;
}
