#!/bin/python
# Joe 2022


import fileinput
import shutil
import sys
import os

src = "0.0_Template"

print("Wizzard for making a new challenge project from template\n --Joe\n\n")

projName = input("Enter project Name   (Ex. HelloWorld ): ")
projNum = input("Enter project Number (Ex. 1.19)       : ")

# Copy all files
shutil.copytree(src, f"{projNum}_{projName}/")
