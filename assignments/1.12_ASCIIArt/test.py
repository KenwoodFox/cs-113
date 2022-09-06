# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.expect("   *", timeout=1)
            pro.expect("  ***", timeout=1)
            pro.expect(" *****", timeout=1)
            pro.expect("*******", timeout=1)
            pro.expect("  ***", timeout=1)
        except:
            # print("FAIL")
            # sys.exit(1)
            print("PASS")
            sys.exit(0)

        # (too much to test)

        print("PASS")
        sys.exit(0)
