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
            pro.sendline("2")
            pro.sendline("3")

            pro.expect("60 cents*", timeout=1)

            pro.sendline("101")
            pro.read()

        except Exception as e:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
