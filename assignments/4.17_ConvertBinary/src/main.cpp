/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

#define toBin(n) (if (n > 1) {bin(n >> 1);printf("%d", n & 1); })
#define fromBin(n)

int main()
{
    char inp[32]; // User input is limited to a maximum of 32 bit integer.
    scanf("%s", &inp);

    for (uint8_t i; i < (sizeof(inp) / sizeof(inp[0])); i++){
printf("%c", inp[i]);
    }

    

    printf(MOTD); // Print build info
    return 0;
}
