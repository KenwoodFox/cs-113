/* Team 4
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <iostream>

using namespace std;

enum LetterGrades
{
    A = 95,
    B = 85,
    C = 75,
    D = 65,
};

int main()
{
    int testScore;

    cin >> testScore;

    if (testScore > A)
    {
        cout << "A" << endl;
    }
    else if (testScore > B)
    {
        cout << "B" << endl;
    }
    else if (testScore > C)
    {
        cout << "C" << endl;
    }
    else if (testScore > D)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }

    printf(MOTD); // Print build info
    return 0;
}
