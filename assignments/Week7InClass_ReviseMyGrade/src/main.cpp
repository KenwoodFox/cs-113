/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

static const int classSize = 10;

int classGrades[classSize];

int main()
{
    for (uint8_t i = 0; i < classSize; i++)
    {
        do
        {
            printf("Enter a grade for student %d: ", i + 1);
            scanf("%d", classGrades + i);
        } while (!(classGrades[i] <= 100 && classGrades[i] >= 0));
    }

    int sum = 0;
    for (uint8_t i = 0; i < classSize; i++)
    {
        sum += classGrades[i];
    }
    int avg = sum / classSize;

    printf("The sum is %d,\nThe class average is %d.\n", sum, avg);

    printf(MOTD); // Print build info
    return 0;
}
