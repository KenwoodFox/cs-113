# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("4")
            pro.sendline("9")
            pro.expect(
                "Volume of a cone with radius 4.0 and height 9.0, 150.8*", timeout=1
            )
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
