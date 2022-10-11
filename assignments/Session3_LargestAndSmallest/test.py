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
            pro.sendline("3")
            pro.sendline("14")
            pro.sendline("10")
            pro.sendline("44")
            pro.expect("Done! The largest is 44 and the smallest is 3.*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
