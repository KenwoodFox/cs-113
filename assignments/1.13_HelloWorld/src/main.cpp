/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>

int main()
{
    std::cout << "Hello world!\nHow are you?\n   (I'm fine).\n";

    std::cout << MOTD; // Print build info
    return 0;
}
