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
            pro.sendline("5")
            pro.sendline("1")
            pro.sendline("5")
            pro.sendline("10")
            pro.sendline("2")
            pro.sendline("5")
            pro.sendline("10")
            pro.sendline("-1")
            pro.expect("Software version 218fdb83*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
