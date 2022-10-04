/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

int getMonth(char *_month);

enum Season
{
    spring, // March 20 - June 20
    summer, // June 21 - September 21
    autumn, // September 22 - December 20
    winter, // December 21 - March 19
};

int main()
{
    char in_month[15];
    int in_day;

    scanf("%s", in_month);
    // scanf("%d", in_day);

    printf("%d", getMonth(in_month));

    printf(MOTD); // Print build info
    return 0;
}

const char *const months[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

int getMonth(char *_month)
{
    // Find a match, yes this could be done with std::string but i feel like that may be cheating
    for (uint8_t i = 0; i < (sizeof(months) / sizeof(char *)) - 1; i++)
    {
        printf("Try match %s with %s at %d\n", _month, months[i], i);
        bool match = true;
        for (uint8_t t = 0; t < (sizeof(months[i]) / sizeof(months[0][0]) - 1); t++)
        {
            printf("Match %c and %c (Scanning %d chars)\n", months[i][t], _month[t], (sizeof(months[i]) / sizeof(months[0][0]) - 1));
            if (months[i][t] != _month[t])
            {
                match = false;
            }
        }
        if (match)
        {
            return i;
        }
    }

    return -1;
}
