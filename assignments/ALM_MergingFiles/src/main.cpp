/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>
#include <fstream>

int main(int argc, char *argv[])
{
    // Merging files
    std::ifstream infile1;
    infile1 >> std::noskipws;
    std::ifstream infile2;
    infile2 >> std::noskipws;
    std::ofstream outfile;

    infile1.open(argv[1]);
    infile2.open(argv[2]);
    outfile.open(argv[3]);

    char _symb;
    while (infile1 >> _symb)
    {
        printf("%c", _symb);
        outfile << _symb;
    }
    outfile << " ";
    while (infile2 >> _symb)
    {
        printf("%c", _symb);
        outfile << _symb;
    }

    infile1.close();
    infile2.close();
    outfile.close();

    // This is so messy!

    printf(MOTD); // Print build info
    return 0;
}
