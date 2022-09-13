/* Team 2
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

uint16_t my_num = 0;

int main()
{
    printf("Enter a number, we'll add one to it [1]: ");
    scanf("%d", &my_num);

    my_num++;
    printf("Your number plus one \t\t(++) is %d\n", my_num);

    my_num += 2;
    printf("Your number plus equals 2 \t(+= 2) is %d\n", my_num);

    my_num--;
    printf("Your number minus one \t\t(--) is %d\n", my_num);

    printf(MOTD); // Print build info
    return 0;
}
