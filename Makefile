projName = file_comparison
compileCmd = gcc -Wall -pedantic-errors $(projName).c -g -o $(projName).out

Compile: $(projName).out
$(projName).out: $(projName).c
  $(compileCmd)

Run: $(projName).out
  ./$(projName).out

Clean:
  rm $(projName).out