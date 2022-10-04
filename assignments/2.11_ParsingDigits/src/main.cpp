/* Joe
 * 2022
 */

/* An easier solution does exist, you could
 * do this purely with string manipulation
 * but that would not be in the spirit of the problem.
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <iostream>
#include <cmath>

// Prototype functions
uint32_t nth_digit(uint32_t num, uint8_t n);
uint32_t n_digits(uint32_t number);

uint32_t userDigit;

int main()
{
    std::cin >> userDigit; // Expect a user digit

    // Truncate
    // for (uint8_t i = 0; i < n_digits(userDigit); i++)
    // {
    //     // The - i -1 allows us to iterate in reverse (starting with most significant digit first)
    //     std::cout << nth_digit(userDigit, n_digits(userDigit) - i - 1) << "   ";
    // }

    // Do not truncate (dumb)
    for (uint8_t i = 0; i < 4; i++)
    {
        if (i != 0)
        {
            std::cout << "   ";
        }

        // The - i -1 allows us to iterate in reverse (starting with most significant digit first)
        std::cout << nth_digit(userDigit, 3 - i);
    }

    std::cout << MOTD; // Print build info
    return 0;
}

/*
 * Return the nth digit in a larger digit (base 10)
 */
uint32_t nth_digit(uint32_t num, uint8_t n)
{
    return (num / uint32_t(pow(10, n))) % 10;
}

/* Returns the number of
 * base 10 digits in a number.
 */
uint32_t n_digits(uint32_t number)
{
    uint32_t count = 0;
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}
