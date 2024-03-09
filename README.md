# File Differences Syscalls
This project focuses on implementing file comparison functionality using system calls in the C programming language. The program reads the contents of two input files, compares them byte-by-byte, and writes the differences into separate output files. Additionally, the program calculates the time taken for each step of the process.

## Design Overview
The program consists of a single file, `file_comparison.c`, which implements the file comparison functionality using system calls like open, close, read, and write. The implementation ensures efficient reading, comparison, and writing of file contents using dynamically allocated memory for arrays.

## Functionality
`file_comparison.c`:
- Implements the main functionality of comparing two input files and writing differences into separate output files.
- Uses system calls like `open`, `close`, `read`, and `write` for file I/O operations.
- Includes two steps:
  - `step1`: Compares input files byte-by-byte and writes differences into `differencesFoundInFile1.txt`. As `step1` accesses the files, not within the program, one byte at a time followed by a null character, it generally takes a longer time to process than `step2`.
  - `step2`: Reads input files into dynamically allocated arrays, compares the arrays, and writes differences into `differencesFoundInFile2.txt`.
- Calculates and outputs the time taken for each step using `gettimeofday()`.

## File Structure and Content
```
file-differences-syscalls/
├── file_comparison.c
├── Makefile
├── README.md
└── resources/
    ├── alice1.txt
    ├── alice2.txt
    ├── input1.txt
    ├── input2.txt
    ├── input3.txt
    ├── input4.txt
    ├── input5.txt
    └── input6.txt
```