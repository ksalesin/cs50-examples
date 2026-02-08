#----------------------------------------------------------------------
#
# Filename: Makefile
# Description:
#
# Date       Pgm  Comment
# 01 Feb 26  jpb  Creation.
#
#
CC = gcc
CFLAGS = -Wall -Wextra -g -pedantic

all: log_analyzer

log_analyzer: log_analyzer.c file_utils.c
	$(CC) $(CFLAGS) -o log_analyzer log_analyzer.c file_utils.c

clean:
	rm -f log_analyzer summary.txt errors.log log_analyzer.bak

test: log_analyzer
	@echo "Running log analyzer on sample.log..."
	@./log_analyzer sample.log
	@echo ""
	@echo "=== summary.txt ==="
	@cat summary.txt
	@echo ""
	@echo "=== errors.log ==="
	@cat errors.log

.PHONY: all clean test
