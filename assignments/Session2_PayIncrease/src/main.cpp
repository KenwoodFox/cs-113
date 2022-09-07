/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// Const
static const double STD_PAY_INCREASE = 7.5; // 8 bytes

int main()
{
    printf("Enter your current salary: $");
    double salary;
    scanf("%lf", &salary);

    salary = salary + (salary * (STD_PAY_INCREASE / 100));

    printf("Your new salary will become $%-5.2lf next year.\n", salary);

    printf(MOTD); // Print build info
    return 0;
}
