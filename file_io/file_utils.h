/*----------------------------------------------------------------------
 *
 * Filename: file_utils.h
 * Description:
 *
 * Date       Pgm  Comment
 * 01 Feb 26  jpb  Creation.
 *
 */
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stddef.h>

// Open a file with error handling
// Return NULL and print error message if open fails
FILE* safe_fopen(const char* filename, const char* mode);

// Count the total number of lines in a file
// The file position should be back at the beginning when done
int count_lines(FILE* fp);

// Read the next line from the log file into the buffer
// Return 1 on success, 0 on EOF, -1 on error
int read_log_entry(FILE* fp, char* buffer, size_t buffer_size);

// Write the log summary to a file
// Return 0 on success, -1 on error
int write_summary(const char* filename, int info_count, int warning_count, int error_count);

// Read through the log file and write all ERROR lines to error_file
// Return the number of errors found, or -1 on error
int extract_errors(FILE* log_fp, const char* error_filename);

// BONUS: Copy a file byte-by-byte using binary mode
// Return 0 on success, -1 on error
int copy_file_binary(const char* source, const char* destination);

#endif
