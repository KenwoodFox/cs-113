# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("10")
            pro.sendline("2")
            pro.sendline("25")
            pro.sendline("-3")
            pro.sendline("22")
            pro.sendline("-14")
            pro.sendline("-14")
            pro.sendline("0")
            pro.sendline("11")
            pro.sendline("16")

            pro.expect("Sum of positive numbers         86", timeout=1)
            pro.expect("Number of positive numbers      6", timeout=1)
            pro.expect("Average of positive numbers     1", timeout=1)

            pro.expect("Sum of negative numbers         -31", timeout=1)
            pro.expect("Number of negative numbers      4", timeout=1)
            pro.expect("Average of negative numbers     1", timeout=1)

            pro.expect("Sum of all numbers              10", timeout=1)
            pro.expect("Number of all numbers           10", timeout=1)
            pro.expect("Average of all numbers          1*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
