/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <string>
#include <stdint.h>

int numvals[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
std::string numerals[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"}; // Includes subtractive cases

int genNumeral(int in)
{
    int i = 12;
    for (int i = sizeof(numerals) / sizeof(numerals[0]) - 1; in > 0; i--)
    {
        int d = in / numvals[i]; // Divide into
        in = in % numvals[i];    // Get remainder
        while (d--)
        {
            printf("%s", numerals[i].c_str());
        } // For each sub (i, ii..)
    }

    printf("\n");
}

int main()
{
    int _in = 0;
    printf("Enter a number (for best results, limit to 1-5000: ");
    scanf("%d", &_in);

    // Warnings
    printf("%s", _in <= 0 ? "\u001b[31mWarning! Roman numerals cannot display negative or zero numbers!\u001b[0m\n" : "");
    printf("%s", _in >= 5000 ? "\u001b[31mWarning! Roman numerals become increasingly verbose with large inputs!\u001b[0m\n" : "");

    genNumeral(_in);

    printf(MOTD); // Print build info
    return 0;
}
