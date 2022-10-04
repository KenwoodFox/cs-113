/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

int main()
{
    char letterGrade;

    scanf("%c", &letterGrade);

    // We want the letters to be uppercase for eval, so..
    letterGrade = letterGrade <= 90 && letterGrade >= 65 ? letterGrade : letterGrade - 32; // Map lowercase to uppercase

    switch (letterGrade)
    {
    case 'A':
        printf("Excellent job!");
        break;

    case 'B':
        printf("Still Radical");
        break;

    case 'C':
        printf("C's get degrees");
        break;

    case 'D':
        printf("Dope bro,");
        break;
    case 'F':
        printf("Failed.. you need to retake it!");
        break;

    default:
        printf("I didn't understand that input!");
        return 255;
    }

    printf(MOTD); // Print build info
    return 0;
}
