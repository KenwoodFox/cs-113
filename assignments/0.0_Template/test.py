# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("0")
            pro.sendline("1")

            pro.expect("     1", timeout=1)
            pro.expect("     11", timeout=1)
            pro.expect("00000111", timeout=1)
            pro.expect("000001111", timeout=1)
            pro.expect("00000111", timeout=1)
            pro.expect("     11", timeout=1)
            pro.expect("     11*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
