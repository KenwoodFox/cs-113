/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdint.h>
#include <main.h>

int main()
{
  // Create account datafile
  std::ifstream accFile("accountData.txt");

  std::string buf;

  if (accFile.is_open())
  {
    int inp = std::stoi(getLastLine(accFile).c_str());
    printf("%d", inp);

    // Validate file

    accFile.close();
  }
  else
  {
    printf("Unable to open file!\n");
  }

  printf(MOTD); // Print build info
  return 0;
}
