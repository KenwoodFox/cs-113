/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <chrono>

#include "progressbar.hpp"

long double factorial(const int n)
{
    long double f = 1.0;
    for (int i = 1; i <= n; ++i)
        f *= i;
    return f;
}

int main()
{
    long iter = 0;
    printf("This program will estimate e using an iterative process.\n");
    printf("Input the number of iterations (1 - 15000 works best): ");
    scanf("%ld", &iter);

    // A nice progress bar!
    progressbar bar(iter);

    // For timing
    auto start = std::chrono::high_resolution_clock::now();

    // Where to store our result
    long double result = 1.0000000000000000000;

    for (int i = 0; i < iter; ++i)
    {
        result += (1.0) / (factorial(i));
        bar.update();
    }

    // Stop the clock!
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    printf("\n\nResult computed in %ldµs and found to be: %0.62Lf.\n", duration.count(), result);

    printf(MOTD); // Print build info
    return 0;
}
