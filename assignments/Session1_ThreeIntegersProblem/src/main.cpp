/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>

uint16_t avgList[3];

int main()
{
    std::cout << "Enter the first integer: ";
    std::cin >> avgList[0];

    std::cout << "Enter the second integer: ";
    std::cin >> avgList[1];

    std::cout << "Enter the third integer: ";
    std::cin >> avgList[2];

    uint16_t avg;
    for (uint8_t i = 0; i < sizeof(avgList) / sizeof(avgList[0]); i++)
    {
        avg += avgList[i];
    }

    std::cout << "Sum of three numbers is " << avg << "\n";
    avg = avg / (sizeof(avgList) / sizeof(avgList[0]));
    std::cout << "Mean of three numbers is " << avg << "\n";

    std::cout
        << MOTD; // Print build info
    return 0;
}
