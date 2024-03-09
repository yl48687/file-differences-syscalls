#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Compares input files one and two by accessing 1 byte at a time from each of the files, comparing
 * them, and writing any byte from file one that is not equal to the corresponding byte in file two
 * into the file called differencesFoundInFile1.txt.
 */
void step1(const char *, const char *);

/**
 * Compares input files one and two by reading both of the files into two dynamically allocated
 * arrays. The input arrays are allocated to be the exact size needed. Then, compares the two arrays
 * and writes any byte from file two that is not equal to the corresponding byte in file one into a
 * third array (also dynamically allocated), and then copies that third array into a file called
 * differencesFoundInFile2.txt.
 */
void step2(const char *, const char *);

/**
 * Compares two input text files and writes every byte in file one that is different from file two
 * into a third file named differencesFoundInFile1.txt and every byte that is different in file two
 * from file one into a fourth file named differencesFoundInFile2.txt. If
 * differencesFoundInFile1.txtor differencesFoundInFile2.txt exists in the present working
 * directory, then the program overwrites the file(s) with new output. If these output files do not
 * exist in the present working directory, then the program creates these files and assigns both of
 * them read and write permissions to the owner.
 */
int main(int argc, char * argv[]) {
    // Prints a message of correct usage of the program
    if (argc != 3) {
        printf("Usage: proj3.out <file1> <file2>\n");
        exit(EXIT_FAILURE);
    } // if

    // Opens file1 and file2 to check for nullity
    FILE * file1 = fopen(argv[1], "r");
    FILE * file2 = fopen(argv[2], "r");

    // Prints an error message of reading files
    if (file1 == NULL || file2 == NULL) {
        printf("There was an error reading a file.\n");
        exit(EXIT_FAILURE);
    } // if

    // Closes the open files
    fclose(file1);
    fclose(file2);

    // Runs step1 and step2
    step1(argv[1], argv[2]);
    step2(argv[1], argv[2]);

    return 0;
} // main

void step1(const char * argv1, const char * argv2) {
    // A data (struct)ure for timeval
    struct timeval start, end;

    // Stores the start time
    gettimeofday(&start, NULL);

    FILE * file1;
    FILE * file2;
    FILE * file3;

    // Opens files
    file1 = fopen(argv1, "r");
    file2 = fopen(argv2, "r");
    file3 = fopen("differencesFoundInFile1.txt", "w");

    int characterFile1 = fgetc(file1);
    int characterFile2 = fgetc(file2);

    // Accesses one byte at a time from each of the files and finds differences
    while (characterFile1 != EOF) {
        if (characterFile1 != characterFile2) {
            fputc(characterFile1, file3);
        } // if
        characterFile1 = fgetc(file1);
        characterFile2 = fgetc(file2);
    } // while

    // Closes all open files
    fclose(file1);
    fclose(file2);
    fclose(file3);

    // Stores the end time and prints the total time took to process step1
    gettimeofday(&end, NULL);
    printf("Step 1 took %f milliseconds\n", ((double)end.tv_usec - (double)start.tv_usec) / 1000);
} // compareFiles

void step2(const char * argv1, const char * argv2) {
    // A data (struct)ure for timeval
    struct timeval start, end;

    // Stores the start time
    gettimeofday(&start, NULL);

    FILE * file1;
    FILE * file2;
    FILE * file3;

    // Opens files
    file1 = fopen(argv1, "r");
    file2 = fopen(argv2, "r");
    file3 = fopen("differencesFoundInFile2.txt", "w");

    // A data (struct)ure for stat
    struct stat statFile1, statFile2;

    // Retrieves information from the files
    stat(argv1, &statFile1);
    stat(argv2, &statFile2);

    // Stores the total sizes of the files in bytes
    int sizeFile1 = statFile1.st_size;
    int sizeFile2 = statFile2.st_size;

    // Creates arrays to store bytes
    char * arrayFile1 = malloc(sizeFile1);
    char * arrayFile2 = malloc(sizeFile2);
    fread(arrayFile1, sizeFile1, 1, file1);
    fread(arrayFile2, sizeFile2, 1, file2);

    // Checks for differences and writes to file
    for (int i = 0; i < sizeFile2; i++){
        if (arrayFile1[i] != arrayFile2[i]){
            fwrite(&arrayFile2[i], 1, 1, file3);
        } // if
    } // for

    // Frees and closes all open files
    free(arrayFile1);
    free(arrayFile2);
    fclose(file1);
    fclose(file2);
    fclose(file3);

    // Stores the end time and prints the total time took to process step2
    gettimeofday(&end, NULL);
    printf("Step 2 took %f milliseconds\n", ((double)end.tv_usec - (double)start.tv_usec) / 1000);
} // step2
