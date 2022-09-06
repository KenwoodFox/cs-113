# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.expect("Enter integer:", timeout=1)
            pro.sendline("4")
            pro.expect("You entered: 4", timeout=1)
            pro.expect("4 squared is 16 ", timeout=1)
            pro.expect("And 4 cubed is 64!!", timeout=1)
            pro.expect("Enter another integer:", timeout=1)
            pro.sendline("5")
            pro.expect("4 + 5 is 9", timeout=1)
            pro.expect("4 * 5 is 20*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
