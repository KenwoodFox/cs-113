# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("7500")
            pro.expect("Result computed in*", timeout=20)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
