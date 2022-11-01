/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

using namespace std; // For some reason, zybooks unit tester shits the bed if this is not here

static const double LAPS_PER_MILE = 4.0;

double MilesToLaps(double userMiles)
{
    return userMiles * LAPS_PER_MILE;
}

int main()
{
    double _in;
    scanf("%lf", &_in);
    printf("%0.2g\n", MilesToLaps(_in));

    printf(MOTD); // Print build info
    return 0;
}
