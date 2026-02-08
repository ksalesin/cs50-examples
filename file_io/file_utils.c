/*----------------------------------------------------------------------
 *
 * Filename: file_utils.c
 * Description:
 *
 * Date       Pgm  Comment
 * 01 Feb 26  jpb  Creation.
 *
 */
#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256

// TODO 1: Implement safe_fopen
// Open a file with error handling
// Return NULL and print error message if open fails
FILE* safe_fopen(const char* filename, const char* mode) {
    // YOUR CODE HERE
    return NULL;
}

// TODO 2: Implement count_lines
// Count the total number of lines in a file
// The file position should be back at the beginning when done
//
// Hints:
//   fgets(char *str, int n, FILE *fp) 
//   will fetch one line of text (of max length n)
//   from the file fp and store it in buffer
//
//   rewind(fp) will rewind the file pointer back to
//   the beginning
int count_lines(FILE* fp) {
    // YOUR CODE HERE
    return 0;
}

// TODO 3: Implement read_log_entry
// Read the next line from the log file into the buffer
// Return 1 on success, 0 on EOF, -1 on error
// Hint: Use fgets() and check both feof() and ferror()
int read_log_entry(FILE* fp, char* buffer, size_t buffer_size) {
    // YOUR CODE HERE
    return 0;
}

// TODO 4: Implement write_summary
// Write the log summary to a file
// Format:
//   Log Analysis Summary
//   ====================
//   INFO:    X
//   WARNING: X  
//   ERROR:   X
//   Total:   X
// Return 0 on success, -1 on error
int write_summary(const char* filename, int info_count, int warning_count, int error_count) {
    // YOUR CODE HERE
    return -1;
}

// TODO 5: Implement extract_errors
// Read through the log file and write all ERROR lines to error_file
// Return the number of errors found, or -1 on error
// Hint: Use strstr() to check if a line contains "ERROR"
int extract_errors(FILE* log_fp, const char* error_filename) {
    // YOUR CODE HERE
    return -1;
}

// BONUS TODO 6: Implement copy_file_binary
// Copy a file byte-by-byte using binary mode
// This demonstrates binary I/O
// Return 0 on success, -1 on error
int copy_file_binary(const char* source, const char* destination) {
    // YOUR CODE HERE
    return -1;
}
