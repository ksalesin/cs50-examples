### Activity: Build a Simple Log File Analyzer

Here is a partially complete program that reads and analyzes a log file; complete the missing functions to make it work.

### Scenario

A server generates log files with entries like:
```
2024-01-15 08:30:45 INFO User login: alice
2024-01-15 08:31:02 ERROR Connection timeout: 10.0.0.5
2024-01-15 08:31:15 INFO User login: bob
2024-01-15 08:32:00 WARNING Disk usage: 85%
```

Complete the program so that it:
1. Reads the log file
2. Counts entries by severity (INFO, WARNING, ERROR)
3. Writes a summary report
4. Extracts and saves all ERROR entries to a separate file

There are five routines to complete. A sixth one is not used by default in the program, but is there if you have some extra time.
To test the sixth routine, define EXTRA.

### Testing

The application can be tested by running `make test`. You can use `diff` to compare your output to the ones in the directory `expected_output`.

### Completion
Your group should turn in `file_utils.c` to Canvas.

### Starter Code Structure

```
activity/
├── Makefile
├── log_analyzer.c      # Main program
├── file_utils.h        # Header file
├── file_utils.c        # File operations (complete this)
├── sample.log          # Test log file
└── expected_output/    # Reference outputs
    ├── summary.txt
    └── errors.log
```
