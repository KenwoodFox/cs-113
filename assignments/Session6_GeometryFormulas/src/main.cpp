/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <geometry.h>

int main()
{
    double _r, _h;
    printf("Please enter a radius to use: ");
    scanf("%lf", &_r);
    printf("Please enter a height to use: ");
    scanf("%lf", &_h);

    printf("Volume of a sphere with radius %.1lf, %.1lf\n", _r, sphere_volume(4));
    printf("Volume of a cylinder with radius %.1lf and height %.1lf, %.1lf\n", _r, _h, cylinder_volume(4, 12));
    printf("Volume of a cone with radius %.1lf and height %.1lf, %.1lf\n", _r, _h, cone_volume(_r, _h));

    printf(MOTD); // Print build info
    return 0;
}
