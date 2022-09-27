/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

static const double COST_PER_LB = 0.99;

int main()
{
    int16_t n_bags, n_applePerBag, n_appleWeight;

    printf("Press return after entering a number.\n\n");
    printf("Enter the number of bags: ");
    scanf("%hi", &n_bags);
    printf("Enter the number of apples in a bag: ");
    scanf("%hi", &n_applePerBag);

    printf("If you have %hi apple bags and %hi apples in a bag, then\n\n", n_bags, n_applePerBag);
    printf("You have %hi apples in all the bags.\n", n_applePerBag * n_bags);
    printf("What is the average weight of one apple (in ounces)? ");
    scanf("%hi", &n_appleWeight);
    int16_t _massApples = n_applePerBag * n_bags * n_appleWeight;
    printf("Total weight is %0.2lf lbs (or %hi ounces)\n", _massApples / 16.0, _massApples);
    printf("Total cost is $%0.2lf", (_massApples / 16.0) * COST_PER_LB);

    printf(MOTD); // Print build info
    return 0;
}
