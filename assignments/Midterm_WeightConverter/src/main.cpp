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
    float _in = 0;

    do
    {
        printf("enter weight in lbs: ");
        scanf("%f", &_in);
    } while (_in < 0.03);

    printf("%0.1f Lbs equals %0.1f kgs\n", _in, _in / 2.2);

    printf(MOTD); // Print build info
    return 0;
}
