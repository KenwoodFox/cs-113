/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

#include <coins.h>

int main()
{
    int16_t n_change;
    change yourChange;

    printf("Enter the number of quarters: ");
    scanf("%2hhx", &yourChange.quarters);

    printf("Enter the number of dimes: ");
    scanf("%2hhx", &yourChange.dimes);

    printf("Enter the number of nickles: ");
    scanf("%2hhx", &yourChange.nickles);

    printf("\tTotal coins worth %d cents\n", getTotalCoinWorth(yourChange));

    printf("Enter the changes (in cents): ");
    scanf("%hd", &n_change);

    yourChange = getChange(n_change);

    printf("\t%d Quarter(s), %d Dime(s), %d Nickel(s), and %d Pennies", yourChange.quarters, yourChange.dimes, yourChange.nickles, yourChange.pennies);

    printf(MOTD); // Print build info
    return 0;
}
