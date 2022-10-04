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
        break;
    }

    printf(MOTD); // Print build info
    return 0;
}
