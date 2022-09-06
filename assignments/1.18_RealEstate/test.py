# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("200000")
            pro.sendline("210000")

            pro.expect(
                "This house is $200000. The change is $-10000 since last month.",
                timeout=1,
            )
            pro.expect("The estimated monthly mortgage is $850.*", timeout=1)
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
