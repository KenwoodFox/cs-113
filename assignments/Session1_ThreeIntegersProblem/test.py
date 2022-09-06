# Written by joe

import os, sys
from socket import timeout
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("4")
            pro.sendline("2")
            pro.sendline("7")

            pro.expect("Sum of three numbers is 13", timeout=1)
            pro.expect("Mean of three numbers is 4*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
