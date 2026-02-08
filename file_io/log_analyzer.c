/*----------------------------------------------------------------------
 *
 * Filename: log_analyzer.c
 * Description: Read a log file, output a summary count and an error log.
 *
 * Date       Pgm  Comment
 * 01 Feb 26  jpb  Creation.
 *
 */
#include <stdio.h>
#include <string.h>
#include "file_utils.h"

#define MAX_LINE 256

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE* log_fp = safe_fopen(argv[1], "r");
    if (!log_fp) return 1;

    int info = 0, warning = 0, error = 0;
    char line[MAX_LINE];

    // Count entries by severity
    while (read_log_entry(log_fp, line, sizeof(line)) == 1) {
        if (strstr(line, "INFO")) info++;
        else if (strstr(line, "WARNING")) warning++;
        else if (strstr(line, "ERROR")) error++;
    }

    // Write summary
    if (write_summary("summary.txt", info, warning, error) != 0) {
        fprintf(stderr, "Failed to write summary\n");
    }

    // Extract errors to separate file
    rewind(log_fp);
    int error_count = extract_errors(log_fp, "errors.log");
    if (error_count >= 0) {
        printf("Extracted %d error entries to errors.log\n", error_count);
    }

    fclose(log_fp);

#ifdef EXTRA
    int success = copy_file_binary ("./log_analyzer", "./log_analyzer.bak");
    if (success < 0)
        perror ("Binary copy failed");
#endif /* EXTRA */

    return 0;
}
