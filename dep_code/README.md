# GDB and Valgrind Debugging Exercise

## Overview
This program contains multiple intentional bugs for you to find and fix using `gdb` and `valgrind`.

## Bugs in This Program
There are several different types of bugs:
1. **Memory leak** - Allocated memory that's never freed
2. **Use after free** - Accessing memory after it's been freed
3. **Buffer overflow** - Writing beyond array bounds
4. **Uninitialized memory read** - Reading values that were never set
5. **Null pointer dereference** - Dereferencing a NULL pointer

## Setup Instructions

### Copy the files
Copy the files from `/home/cs50/shared/examples/dep_code` to your home directory on `plink`.

### Compile the program
```bash
make dep
# There is also a cleanup action
make clean
```

## Part 1: Using Valgrind

Valgrind helps detect memory errors and leaks.

### Run with Valgrind
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./dep
```

### What to look for:
- **Invalid read/write**: Accessing memory you shouldn't
- **Use of uninitialized values**: Reading variables that were never set
- **Memory leaks**: Memory allocated but never freed
- **Invalid free**: Freeing memory incorrectly

### Part 1 Exercise Questions:
1. How many bytes are "definitely lost" in the memory leak?
2. Which function causes the "Invalid write" error?
3. What line number has the use-after-free bug?
4. Where is uninitialized memory being read?

## Part 2: Using GDB

GDB helps you debug crashes and understand program flow.

### Run with GDB
```bash
gdb ./dep
```

### Some useful GDB Commands:
```
(gdb) run                    # Run the program
(gdb) break main             # Set breakpoint at main
(gdb) break 45               # Set breakpoint at line 45
(gdb) next                   # Execute next line (step over)
(gdb) step                   # Step into function
(gdb) continue               # Continue execution
(gdb) print variable_name    # Print variable value
(gdb) backtrace              # Show call stack (useful after crash)
(gdb) list                   # Show source code
(gdb) info locals            # Show local variables
(gdb) quit                   # Exit gdb
```

### Part 2 Exercise Tasks:
1. Run the program in gdb. Where does it crash?
2. Use `backtrace` to see which function caused the crash
3. Set a breakpoint before the crash and step through the code
4. Print the value of variables to understand the bug
5. Fix the crash and re-run

## Verification

After fixing all bugs:
```bash
# Recompile
make dep

# Should run without crashing
./dep

# Should show no errors and no leaks
valgrind --leak-check=full ./dep
```

You should see:
- No segmentation fault
- No valgrind errors
- "All heap blocks were freed -- no leaks are possible."

### Turn in the answered questions from Part 1 and the completely repaired `dep.c` file to Canvas.
