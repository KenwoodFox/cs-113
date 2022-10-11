/* Team 4 <3
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

static const int REG_PAY_PER_HR = 20;
static const int MAX_HOURS = 40;
static const double OVERTIME_MOD = 1.5;

int main()
{
    int hours_worked = 0;

    printf("Enter your hours worked this week: ");

    scanf("%d", &hours_worked);

    int regular_hours, overtime_hours;
    regular_hours = hours_worked > MAX_HOURS ? 40 : hours_worked;             // Truncate
    overtime_hours = hours_worked > MAX_HOURS ? hours_worked - MAX_HOURS : 0; // Truncate

    printf("You worked %d hours, %d of witch are paid at your regular rate $%d/hr, and the other %d are %.1lf times that.\n\n", hours_worked, regular_hours, REG_PAY_PER_HR, overtime_hours, OVERTIME_MOD);
    double reg_pay = regular_hours * REG_PAY_PER_HR;
    double overtm_pay = overtime_hours * (OVERTIME_MOD * REG_PAY_PER_HR);
    printf("Normal  \t%d\t$%0.2lf\nOvertime\t%d\t$%0.2lf\n\nTotal   \t$%.2lf", regular_hours, reg_pay, overtime_hours, overtm_pay, reg_pay + overtm_pay);

    printf(MOTD); // Print build info
    return 0;
}
