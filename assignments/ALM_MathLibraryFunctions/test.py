# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.expect(
                "45      45              6.70820         6       7       1.90333*",
                timeout=1,
            )
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
