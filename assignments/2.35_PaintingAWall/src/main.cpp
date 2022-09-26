/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

// How many sqft one gallon covers
static const uint16_t AREA_PER_GAL = 350;
// Each can is one gallon
static const uint16_t GAL_PER_CAN = 1;
// Tax rate
static const double TAX = 0.07;

int main()
{
    double _w, _h;
    double cost_per_can;

    scanf("%lf", &_w);
    scanf("%lf", &_h);
    scanf("%lf", &cost_per_can);

    double wall_area = _w * _h;
    printf("Wall area: %.1lf sq ft\n", wall_area);
    double paint_vol = wall_area / AREA_PER_GAL;
    printf("Paint needed: %.3lf gallons\n", paint_vol);
    double cans_needed = static_cast<int>(paint_vol + 1);
    printf("Cans needed: %.0lf can(s)\n", cans_needed);
    double cost = cans_needed * cost_per_can;
    printf("Paint cost: $%.2lf\n", cost);
    double tax = cost * TAX;
    printf("Sales tax: $%.2lf\n", tax);
    printf("Total cost: $%.2lf\n", cost + tax);

    printf(MOTD); // Print build info
    return 0;
}
