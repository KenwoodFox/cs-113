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
int statList[STAT_SIZE];

int main()
{
    // We'll iterate through and collect all the data points we want.. namely:
    int posAvg, posCt, posSum, negAvg, negCt, negSum, sum, avg;
    sum = -0; // Magic c99 stuff? Ew..
    negSum = -0;
    negCt = -0;

    // Iterate and collect an integer for each value in our statList
    for (uint8_t i = 0; i < STAT_SIZE; i++)
    {
        printf("Enter an integer (%d/%d): ", i + 1, STAT_SIZE);
        scanf("%d", statList + i); // Sorta clunky cuz pointers but, whateveah~
    }

    for (uint8_t i = 0; i < sizeof(statList) / sizeof(statList[0]); i++)
    {
        if (statList[i] > 0)
        { // we'll treat 0 as non-positive
            posCt++;
            posSum += statList[i];
        }
        else
        {
            negCt++;
            negSum += statList[i];
        }

        sum++;
        avg += statList[i];
    }

    posAvg = posCt != 0 ? posSum / posCt : 0;
    negAvg = negCt != 0 ? negSum / negCt : 0;
    avg = sum / STAT_SIZE;

    printf("\nSum of positive numbers \t%d\n", posSum);
    printf("Number of positive numbers \t%d\n", posCt);
    printf("Average of positive numbers \t%d\n", posAvg);

    printf("\nSum of negative numbers \t%d\n", negSum);
    printf("Number of negative numbers \t%d\n", negCt);
    printf("Average of negative numbers \t%d\n", negAvg);

    printf("\nSum of all numbers \t\t%d\n", sum);
    printf("Number of all numbers \t\t%d\n", STAT_SIZE);
    printf("Average of all numbers \t\t%d\n", avg);

    printf(MOTD); // Print build info
    return 0;
}
