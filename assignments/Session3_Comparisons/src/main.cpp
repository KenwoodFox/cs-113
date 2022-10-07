/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

int main()
{
    double _na, _nb; // Two numbers to read in

    printf("Enter first number: ");
    scanf("%lf", &_na);
    printf("Enter second number: ");
    scanf("%lf", &_nb);

    printf("%.0lf %s %.0lf\n", _na, _na == _nb ? "==" : "!=", _nb);
    printf("%.0lf %s %.0lf\n", _na, _na >= _nb ? ">=" : "<", _nb);
    printf("%.0lf %s %.0lf\n", _na, _na <= _nb ? "<=" : "<", _nb);

    printf(MOTD); // Print build info
    return 0;
}
