from __future__ import print_function
import os, sys

def checkForFile(fname):
    print("Checking for %s... " % fname, end="")
    if (not os.path.isfile(fname)):
        print("%s not found" % fname)
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    print("found\n")

def unpacktar(fname):
    print("Unpacking %s into _testdir..." % fname, end="")
    if (not os.path.isfile(fname)):
        print("%s not found" % fname)
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()

    os.system("rm -rf _testdir")
    os.system("mkdir _testdir")
    os.system("cp %s ./_testdir" % fname)
    os.chdir("_testdir")
    os.system("tar -xzf %s" % fname)

    print("done\n")

    print("Checking for Makefile... ", end="")
    if (not os.path.isfile("Makefile")):
        print("not found")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    print("found\n")

def runWithArguments(executable, arguments):
    print("\n----------")
    print("Running '%s %s'\n" % (executable, arguments))
    print("your program output is\n")
    val = os.system("./%s %s" % (executable, arguments))
    print("----------\n")

def runWithInput(executable,inputString):
    print('\n----------')
    print("Running '%s'\n" % executable)
    print("For input\n\n%s\n" % inputString)
    print("your program output is\n")
    val = os.system("echo '%s' | ./%s" % (inputString,executable))
    print('----------\n')

def test3p3():
    print("\n*********************")
    print("*** TESTING Exercise 3.3 ***")
    print("*********************\n")

    print("Running 'make testWrite'... ")
    if (os.system("make testWrite") != 0):
        print("\n!!! Failed to generate testWrite !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    print("")

    n = 5
    runWithArguments("./testWrite", str(n))

    runWithArguments("./testWrite", str(n)+" testWrite_output1")

    # check testWrite_output1
    checkForFile("testWrite_output1")
    try:
        f = open('./testWrite_output1', "r")
    except:
        print("Can't open testWrite_output1.\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    lines = f.readlines()
    try:
        if lines[0].rstrip("\n") != "AMATH 583 VECTOR" or \
           int(lines[1].rstrip("\n")) != n or \
           lines[n+2].rstrip("\n") != "THIS IS THE END":
            raise Exception("")
        else:
            print("\nContent in testWrite_output1 is correct.\n")
    except:
        print("\n!!! You didn't write correct content to testWrite_output1 !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    f.close()

    runWithArguments("./testWrite", "0 testWrite_output2")

    # check testWrite_output2
    checkForFile("testWrite_output2")
    try:
        f = open('./testWrite_output2', "r")
    except:
        print("Can't open testWrite_output2.\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    lines = f.readlines()
    try:
        if lines[0].rstrip("\n") != "AMATH 583 VECTOR" or \
           lines[1].rstrip("\n") != "THIS IS THE END":
            raise Exception("")
        else:
            print("\nContent in testWrite_output2 is correct.\n")
    except:
        print("\n!!! You didn't write correct content to testWrite_output2 !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    f.close()

    runWithArguments("./testWrite", "-4")
    runWithArguments("./testWrite", "")

def test3p4():
    print("\n*********************")
    print("*** TESTING Exercise 3.4 ***")
    print("*********************\n")

    print("Running 'make infRandom'... ")
    if (os.system("make infRandom") != 0):
        print("\n!!! Failed to generate infRandom !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    print("")

    n = 5
    runWithArguments("./infRandom", str(n))
    runWithArguments("./infRandom", str(n)+" cout")

    runWithArguments("./infRandom", str(n)+" infRandom_output")
    # check infRandom_output
    checkForFile("infRandom_output")
    try:
        f = open('./infRandom_output', "r")
    except:
        print("Can't open infRandom_output.\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    lines = f.readlines()
    try:
        if lines[0].rstrip("\n") != "AMATH 583 VECTOR" or \
           int(lines[1].rstrip("\n")) != n or \
           lines[n+2].rstrip("\n") != "THIS IS THE END":
            raise Exception("")
        else:
            print("\nContent in infRandom_output is correct.\n")
    except:
        print("\n!!! You didn't write correct content to infRandom_output !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    f.close()

    runWithArguments("./infRandom", "")



def test3p5():
    print("\n*********************")
    print("*** TESTING Exercise 3.5 ***")
    print("*********************\n")

    print("Running 'make dot583'... ")
    if (os.system("make dot583") != 0):
        print("\n!!! Failed to generate dot583 !!!\n")
        print("\n!!! TEST FAILED !!!\n")
        sys.exit()
    print("")

    print("Creating input file, foo.in, that tests dot583... ",end="")
    codestring = \
"""AMATH 583 VECTOR
5
5.5
3.6
4.2
14.1
8.2
THIS IS THE END"""
    if (os.system("echo '%s' > foo.in" % codestring) != 0):
        print("\n!!! Can't create foo.in !!!\n")
        sys.exit()
    print("done")

    print("Creating input file, bar.in, that tests dot583... ",end="")
    codestring = \
"""AMATH 583 VECTOR
5
1.3
9.2
3.8
5.4
5.9
THIS IS THE END"""
    if (os.system("echo '%s' > bar.in" % codestring) != 0):
        print("\n!!! Can't create bar.in !!!\n")
        sys.exit()
    print("done")

    print("Creating input file, different_length.in, that tests dot583... ",end="")
    codestring = \
"""AMATH 583 VECTOR
4
3.6
4.2
14.1
8.2
THIS IS THE END"""
    if (os.system("echo '%s' > different_length.in" % codestring) != 0):
        print("\n!!! Can't create different_length.in !!!\n")
        sys.exit()
    print("done")

    runWithArguments("./dot583","foo.in bar.in")
    print("\nThe output above should be 180.75.\n")
    runWithArguments("./dot583","foo.in different_length.in")
    runWithArguments("./dot583","foo.in")




###############################################################################
if __name__ == "__main__":

    script = \
"""Select Test to Run

0) All
1) Exercise 3.3
2) Exercise 3.4
3) Exercise 3.5 (583 Only)

... (q to quit):
"""

    unpacktar("ps2.tgz")
    response = raw_input(script)
    while (response != "q"):
        if (response == "1" or response == "0"):
            test3p3()
        if (response == "2" or response == "0"):
            test3p4()
        if (response == "3" or response == "0"):
            test3p5()
        response = raw_input(script)
