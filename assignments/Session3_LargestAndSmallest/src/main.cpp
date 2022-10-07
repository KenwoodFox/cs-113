/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// The number of numbers we want to read in.
static const uint8_t INPUT_SIZE = 5;

// Array of size INPUT_SIZE
int inputList[INPUT_SIZE];

int main()
{
    // Collect all our inputs
    for (uint8_t i = 0; i < INPUT_SIZE; i++)
    {
        printf("Enter an integer (%d/%d): ", i + 1, INPUT_SIZE);
        scanf("%d", inputList + i); // Sorta clunky cuz pointers but, whateveah~
    }

    int _sm, _lr = inputList[0]; // Intalize to some array member
    for (uint8_t i = 0; i < sizeof(inputList) / sizeof(inputList[0]); i++)
    {
        if (inputList[i] < _sm)
        {
            _sm = inputList[i];
        }

        if (inputList[i] > _lr)
        {
            _lr = inputList[i];
        }
    }

    printf("\nDone! The largest is %d and the smallest is %d.\n", _lr, _sm);

    printf(MOTD); // Print build info
    return 0;
}
