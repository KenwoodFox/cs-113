# Written by joe

import os, sys
import pexpect

pro = pexpect.spawn("./" + os.environ.get("PROJ_NAME") + "_binary")
pro.logfile = sys.stdout.buffer

try:
    pro.expect("Hello World!*", timeout=1)
except:
    print("FAIL")
    sys.exit(1)

print("PASS")
sys.exit(0)
