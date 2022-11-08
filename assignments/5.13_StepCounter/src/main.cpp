/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// Why the fuck are these needed?
#include <iomanip>
using namespace std;

static const double FEET_PER_STEP = 2.5;

/* This is dumb but required
 * @returns int steps
 */
int FeetToSteps(double userFeet)
{
    return userFeet / FEET_PER_STEP; // return int
}

int main()
{
    double _in;
    scanf("%lf", &_in);

    printf("%d\n", FeetToSteps(_in));

    printf(MOTD); // Print build info
    return 0;
}
