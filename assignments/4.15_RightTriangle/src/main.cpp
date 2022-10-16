/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

void drawTriangle(int sz, char ch);

int main()
{
    int rq_lines = 0;
    char rq_char = '%';

    printf("Enter a character:\n");
    scanf("%c", &rq_char);

    printf("Enter triangle height:\n");
    scanf("%d", &rq_lines);

    drawTriangle(rq_lines, rq_char);

    printf(MOTD); // Print build info
    return 0;
}

void drawTriangle(int sz, char ch = '%')
{
    for (uint8_t i = 0; i < sz + 1; i++)
    {
        for (uint8_t j = 0; j < i; j++)
        {
            printf("%c ", ch);
        }
        printf("\n");
    }
}
