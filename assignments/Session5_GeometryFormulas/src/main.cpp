/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include <geometry.h>

enum Shapes
{
    Sphere,
    Cylinder,
    Cone,
};

int main()
{
    int _userSel = -1;

    do
    {
        printf("Make a selection\n [%d] Sphere\n [%d] Cylinder\n [%d] Cone\n\nEnter -1 at any time to stop.\n", Sphere, Cylinder, Cone);
        scanf("%d", &_userSel);

        double _r, _h;
        switch (_userSel)
        {
        case static_cast<int>(Sphere):
            printf("Enter a value for your sphere's radius.\n");
            scanf("%lf", &_r);

            printf("A sphere with radius %.4lf has volume %.4lf.\n", _r, sphere_volume(_r));
            break;

        case static_cast<int>(Cylinder):
            printf("Enter a value for your Cylinder's radius.\n");
            scanf("%lf", &_r);
            printf("Enter a value for your Cylinder's height.\n");
            scanf("%lf", &_h);

            printf("A cylinder with radius %.4lf and height %.4lf has volume %.4lf.\n", _r, _h, cylinder_volume(_r, _h));
            break;

        case static_cast<int>(Cone):
            printf("Enter a value for your cone's radius.\n");
            scanf("%lf", &_r);
            printf("Enter a value for your cone's height.\n");
            scanf("%lf", &_h);

            printf("A cone with radius %.4lf and height %.4lf has volume %.4lf.\n", _r, _h, cone_volume(_r, _h));
            break;

        default:
            break;
        }
    } while (_userSel != -1);

    printf(MOTD); // Print build info
    return 0;
}
