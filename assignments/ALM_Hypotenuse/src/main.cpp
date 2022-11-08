/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <cmath>

/*
 *Gets a pair of formatted inputs for a triangle.
 *
 * @param sideA Length of side A
 * @param sideB Length of side B
 *
 * @return 0 for success.
 */
int getInputs(float &sideA, float &sideB);

/*
 * Takes a pair of inputs and returns the calculated
 * hypotenuse of a triangle with those sides.
 *
 * @param sideA Length of side A
 * @param sideB Length of side B
 *
 * @return length of hypotenuse (side C)
 */
float calculate_hypt(float sideA, float sideB);

/*
 * Displays the formatted result.
 *
 * @param hyp Hypotenuse to display.
 *
 * @return Nothing
 */
void displayResult(float hyp);

/*
 * A docstring is a formatted, readable component of a
 * C or C++ program that can be read by external docutils
 * or tools such as vim or emacs to provide pourpose and
 * description to functions and modules.
 *
 * @author Joe
 */
int main()
{
    float _sideA, _sideB;
    getInputs(_sideA, _sideB);
    float _hyp = calculate_hypt(_sideA, _sideB);
    displayResult(_hyp);

    printf(MOTD); // Print build info
    return 0;
}

int getInputs(float &sideA, float &sideB)
{
    printf("Enter a side length for A.\n");
    scanf("%f", &sideA);
    printf("Enter a side length for B.\n");
    scanf("%f", &sideB);

    return 0;
}

float calculate_hypt(float sideA, float sideB)
{
    return sqrt(pow(sideA, 2) + pow(sideB, 2));
}

void displayResult(float hyp)
{
    printf("The calculated hypotenuse of your triangle was %0.2f.\n", hyp);
}
