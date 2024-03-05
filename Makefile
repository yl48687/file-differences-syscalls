Yewon Lee
811-280-159

projName = proj3
compileCmd = gcc -Wall -pedantic-errors $(projName).c -g -o $(projName).out

Compile: $(projName).out

    $(projName).out: $(projName).c
	    $(compileCmd)

Run: $(projName).out

    ./$(projName).out

Clean:

    rm $(projName).out

Information:

    As step1 accesses the files, not within the program, one byte at a time
    followed by a null character, step2 copies the files onto arrays used within
    the program. Thus, step1 generally takes a longer time to process than step2.
