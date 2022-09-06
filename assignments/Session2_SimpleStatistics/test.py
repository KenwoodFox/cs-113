# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        averages = [17, 21, 48, 18, 34, 29, 18, 9, 18, 10]

        try:
            for avg in averages:
                pro.sendline(str(avg))

            pro.expect("Sum of three numbers is 222")
            pro.expect("Mean of three numbers is 22*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
