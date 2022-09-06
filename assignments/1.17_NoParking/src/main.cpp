/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <string>

#define startTime 2
#define parkingDuration 4

const char signTitle[] = "  NO PARKING\n";

int main()
{
    std::cout << signTitle;
    std::cout << startTime << ":00 - " << startTime + parkingDuration << ":00 a.m.\n"; // TODO: only supports 0-12

    std::cout << MOTD; // Print build info
    return 0;
}
