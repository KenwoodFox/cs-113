# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("1")
            pro.sendline("1")
            pro.expect(
                "The calculated hypotenuse of your triangle was 1.41.*", timeout=1
            )
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
