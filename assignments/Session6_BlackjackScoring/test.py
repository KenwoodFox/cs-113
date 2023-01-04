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
            pro.sendline("0")
            pro.sendline("0")
            pro.expect(" [1] Yes*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
