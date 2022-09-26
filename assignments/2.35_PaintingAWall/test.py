# Written by joe

import os, sys
import fnmatch
import pexpect

for file in os.listdir("."):
    if fnmatch.fnmatch(file, "*_binary"):
        pro = pexpect.spawn("./" + file)

        pro.logfile = sys.stdout.buffer

        try:
            pro.sendline("8.0")
            pro.sendline("8.0")
            pro.sendline("49.20")
            pro.expect(
                """Wall area: 64.0 sq ft
Paint needed: 0.183 gallons
Cans needed: 1 can(s)
Paint cost: $49.20
Sales tax: $3.44
Total cost: $52.64*""",
                timeout=1,
            )
        except:
            print("FAIL")
            sys.exit(1)

        print("PASS")
        sys.exit(0)
