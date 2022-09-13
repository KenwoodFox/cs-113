/* Team 2 best team
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>

uint16_t my_num = 0;

int main()
{
    std::cout << "Enter a number, I'll perform some reference operations on it [1]: ";
    std::cin >> my_num;

    my_num++;
    std::cout << "Your number plus one \t\t(++) is " << my_num << "\n";

    my_num += 2;
    std::cout << "Your number plus equals 2 \t(+= 2) is " << my_num << "\n";

    my_num--;
    std::cout << "Your number minus one \t\t(--) is " << my_num << "\n";

    std::cout << MOTD; // Print build info
    return 0;
}
