/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

bool isLeapYear(int _y);

int main()
{
    int inYear;

    scanf("%d", &inYear);

    printf("%d is%s a leap year.\n", inYear, isLeapYear(inYear) ? "" : " not");

    printf(MOTD); // Print build info
    return 0;
}

bool isLeapYear(int _y)
{
    bool div_four = _y % 4 == 0;
    bool cen_year;

    if (_y % 100 == 0)
    {
        return _y % 400 == 0;
    }

    return div_four;
}
