/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

float CelsiusToFahrenheit(float _C);
float FahrenheitToCelsius(float _F);

int main()
{
    float userIn;

    printf("\n\nEnter a value in degrees fahrenheit that you would like to see in celsius: ");
    scanf("%f", &userIn);

    printf("%.2f in celsius is %.2f.\n", userIn, FahrenheitToCelsius(userIn));

    printf("Enter a value in degrees celsius that you would like to see in fahrenheit: ");
    scanf("%f", &userIn);

    printf("%.2f in fahrenheit is %.2f.\n", userIn, CelsiusToFahrenheit(userIn));

    printf(MOTD); // Print build info
    return 0;
}

/* Returns a float representing your input temp in degrees fahrenheit
 * @param _C A value in degrees celsius
 */
float CelsiusToFahrenheit(float _C)
{
    return (_C * (9.0 / 5.0)) + 32.0;
}

/* Returns a float representing your input temp in degrees celsius
 * @param _C A value in degrees fahrenheit
 */
float FahrenheitToCelsius(float _F)
{
    return (_F - 32.0) * (5.0 / 9.0);
}
