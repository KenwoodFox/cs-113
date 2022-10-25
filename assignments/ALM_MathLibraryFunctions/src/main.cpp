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
    printf("Number\tAbsolute\tSquare roots\tFloor\tCeiling\tLogarithm\n");
    for (int i = -50; i < 50; i += 5)
    {
        int _abs = abs(i);
        double _sqrt = sqrt(static_cast<double>(_abs));
        printf("%d\t%d\t\t%.5lf\t\t%.0lf\t%.0lf\t%.5lf\n", i, _abs, _sqrt, floor(_sqrt), ceil(_sqrt), log(_sqrt));
    }

    printf(MOTD); // Print build info
    return 0;
}
