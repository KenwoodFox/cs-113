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
    int _na, _nb; // Two numbers to read in

    printf("Enter first number: ");
    scanf("%d", &_na);
    printf("Enter second number: ");
    scanf("%d", &_nb);

    // Print not only if not true.
    printf("%d is %sa multiple of %d", _na, _na % _nb == 0 ? "" : "not ", _nb);

    printf(MOTD); // Print build info
    return 0;
}
