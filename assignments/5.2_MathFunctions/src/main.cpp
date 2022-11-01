/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <cmath>

int main()
{
    double x, y, z;

    scanf("%lf", &x);
    scanf("%lf", &y);
    scanf("%lf", &z);

    printf("%.1lf %0.5e %.0lf %.2lf\n", pow(x, y), pow(x, pow(y, z)), fabs(x), sqrt(pow(x * y, z)));

    printf(MOTD); // Print build info
    return 0;
}
