/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

int main()
{
    std::string name;

    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    std::cout << "Hello " << name << ", and Welcome to CS113 Class!\n";

    std::cout << MOTD; // Print build info
    return 0;
}
