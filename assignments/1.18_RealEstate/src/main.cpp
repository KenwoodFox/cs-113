/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

int currentPrice, lastMonthsPrice;

float getEstMorgage(int curprice);

int main()
{
    // Load in values
    std::cin >> currentPrice;
    std::cin >> lastMonthsPrice;

    std::cout << "This house is $" << currentPrice << ". The change is $" << currentPrice - lastMonthsPrice << " since last month.\n";
    std::cout << "The estimated monthly mortgage is $" << getEstMorgage(currentPrice) << ".\n";

    std::cout << MOTD; // Print build info
    return 0;
}

float getEstMorgage(int curprice)
{
    // From zybooks
    return (curprice * 0.051) / 12;
}
