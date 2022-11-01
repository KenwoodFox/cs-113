/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

using namespace std; // For some reason, zybooks unit tester shits the bed if this is not here
#include <iomanip>   // also requires this too? wtf?

static const double MILES_PER_LAP = 0.25;

double LapsToMiles(double userLaps)
{
    return userLaps * MILES_PER_LAP;
}

int main()
{
    double _in;
    scanf("%lf", &_in);
    printf("%0.2lf\n", LapsToMiles(_in));

    printf(MOTD); // Print build info
    return 0;
}
