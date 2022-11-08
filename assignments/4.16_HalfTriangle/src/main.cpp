/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

void drawHalfArrow(int bh, int bw, int hw);

int main()
{
    int rq_height, rq_width, rq_headWidth;

    printf("Enter arrow base height:\n");
    scanf("%d", &rq_height);
    printf("Enter arrow base width:\n");
    scanf("%d", &rq_width);
    do
    {
        printf("Enter arrow head width:\n");
        scanf("%d", &rq_headWidth);
    } while (rq_headWidth <= rq_width);

    printf("\n"); // buf

    drawHalfArrow(rq_height, rq_width, rq_headWidth);

    printf(MOTD); // Print build info
    return 0;
}

void drawHalfArrow(int bh = 5, int bw = 2, int hw = 4)
{
    for (uint8_t i = 0; i < bh; i++)
    {
        for (uint8_t j = 0; j < bw; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (uint8_t i = 0; i < hw; i++)
    {
        for (uint8_t h = 0; h < hw - i; h++)
        {
            printf("*");
        }
        printf("\n");
    }
}
