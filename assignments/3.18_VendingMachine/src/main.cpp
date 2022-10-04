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
    bool arr[6] = {false};
    for (int i = 0; i < 6; i++)
    {
        int _in;
        scanf("%d", &_in);
        arr[i] = static_cast<bool>(_in);
    }

    bool f_noOrder = true; // Flag for if no order
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == true)
        {
            f_noOrder = false;
        }
    }

    // Print
    if (!f_noOrder)
    {
        arr[0] && arr[1] && arr[2] ? printf("All-snacks ") : printf("%s%s%s", arr[0] ? "Chips " : "", arr[1] ? "Fruit " : "", arr[2] ? "Nuts " : "");
        arr[3] && arr[4] && arr[5] ? printf("All-drinks \n") : printf("%s%s%s\n", arr[3] ? "Juice " : "", arr[4] ? "Water " : "", arr[5] ? "Coffee " : "");
    }
    else
    {
        printf("No items \n");
    }

    printf(MOTD); // Print build info
    return 0;
}
