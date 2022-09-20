/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// The number of datapoints we want to include in our statistics.
static const uint8_t STAT_SIZE = 10;

// Array of size STAT_SIZE
uint16_t avgList[STAT_SIZE];

int main()
{
    // Iterate and collect an integer for each value in our avgList
    for (uint8_t i = 0; i < STAT_SIZE; i++)
    {
        printf("Enter an integer (%d/%d): ", i + 1, STAT_SIZE);
        scanf("%d", avgList + i); // Sorta clunky cuz pointers but, whateveah~
    }

    // Iterate and collect a sum and avg
    uint16_t avg;
    for (uint8_t i = 0; i < sizeof(avgList) / sizeof(avgList[0]); i++)
    {
        avg += avgList[i];
    }

    printf("\nSum of three numbers is %d\n", avg);
    avg = avg / (sizeof(avgList) / sizeof(avgList[0])); // Find avg
    printf("Mean of three numbers is %d\n", avg);

    printf(MOTD); // Print build info
    return 0;
}
