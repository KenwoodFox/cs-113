/* Joe
 * 2022
 */

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdint.h>

bool movStart(std::ifstream &fs)
{
    fs.seekg(-1, std::ios_base::cur);
    for (long i = fs.tellg(); i > 0; i--)
    {
        if (fs.peek() == '\n')
        {
            fs.get();
            return true;
        }
        fs.seekg(i, std::ios_base::beg);
    }
    return false;
}

std::string getLastLine(std::ifstream &fs)
{
    // Go to the last character before EOF
    fs.seekg(-1, std::ios_base::end);
    if (!movStart(fs))
        return "";

    std::string lastline = "";
    getline(fs, lastline);
    return lastline;
}

int main();
