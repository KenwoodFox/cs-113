/* Joe
 * 2022
 */

#ifndef QUARTER_SIZE
#define DOLLAR_SIZE 100
#define QUARTER_SIZE 25
#define DIME_SIZE 10
#define NICKEL_SIZE 5
#define PENNY_SIZE 1
#endif

struct change
{
    int16_t pennies = 0;
    int16_t nickles = 0;
    int16_t dimes = 0;
    int16_t quarters = 0;
};

int16_t getTotalCoinWorth(change _change)
{
    return (QUARTER_SIZE * _change.quarters) + (DIME_SIZE * _change.dimes) + (NICKEL_SIZE * _change.nickles) + (PENNY_SIZE * _change.pennies);
}

int16_t getModuloFit(int16_t &num, int16_t mod)
{
    int16_t numFit = num / mod;
    num = num % mod;

    return numFit;
}

/* Return some change
 */
change getChange(int16_t &cents)
{
    change _ch;

    _ch.quarters = getModuloFit(cents, QUARTER_SIZE);
    _ch.dimes = getModuloFit(cents, DIME_SIZE);
    _ch.nickles = getModuloFit(cents, NICKEL_SIZE);
    _ch.pennies = getModuloFit(cents, PENNY_SIZE);

    return _ch;
}
