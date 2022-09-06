/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

int n1, n2;

int main()
{
    std::cout << "Enter integer:\n";
    std::cin >> n1;
    std::cout << "You entered: " << n1 << "\n";

    std::cout << n1 << " squared is " << n1 * n1 << "\nAnd " << n1 << " cubed is " << n1 * n1 * n1 << "!!\nEnter another integer:\n";
    std::cin >> n2;

    std::cout << n1 << " + " << n2 << " is " << n1 + n2 << "\n";
    std::cout << n1 << " * " << n2 << " is " << n1 * n2 << "\n";

    std::cout << MOTD; // Print build info
    return 0;
}
