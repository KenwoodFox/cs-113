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
            pro.sendline("50")
            pro.sendline("0")
            pro.sendline("2")
            pro.sendline("250")
            pro.sendline("1")
            pro.sendline("0")
            pro.sendline("1400")
            pro.sendline("1")
            pro.expect("Balance remaining: 1000.00*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
