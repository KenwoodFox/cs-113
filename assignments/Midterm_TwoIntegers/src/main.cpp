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
    int n1, n2, sum = 0;

    do
    {
        printf("Enter two numbers ");
        scanf("%d", &n1);
        scanf("%d", &n2);
    } while (n2 < n1);

    for (int i = n1; n1 <= n2; n1++)
    {
        sum += n1;
    }
    printf("Sum is %d\n", sum);

    printf(MOTD); // Print build info
    return 0;
}
