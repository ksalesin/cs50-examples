/*
 * matrix.c
 * Simple matrix struct and operations for memory & pointers practice.
 *
 * Written by Kate Salesin 2026
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * A matrix of integers represented as a nested array,
 * where the outer array contains pointers to each row
 * and each inner array contains a single row.
 */
typedef struct {
    int** nums;
    int n_rows;
    int n_cols;
} matrix_t;

/*
 * Get the element of the matrix at row i and column j.
 *
 * Assumes zero-based indexing, e.g. to get the element 
 * at row 1, column 1, one would call get(m, 0, 0).
 */
int get(matrix_t* m, int i, int j) {
    // TODO
}

/*
 * Swap the elements of the matrix at row i, column j
 * and row j, column i.
 *
 * Assumes zero-based indexing, as above.
 */
void swap(matrix_t* m, int i, int j) {
    // TODO
}

/*
 * Swap the rows r1 and r2 of the matrix.
 *
 * Assumes zero-based indexing, as above.
 */
void swapRows(matrix_t* m, int r1, int r2) {
    // TODO
}

/*
 * Store the elements along the diagonal of matrix m in array d.
 */
void diagonal(matrix_t* m, int* d) {
    // TODO
}

/*
 * Print the matrix with a square bracket at the start and end 
 * of each row, e.g.:
 *
 *   [   1   2   3 ]
 *   [   4   5   6 ]
 *   [   7   8   9 ]
 * 
 * You can assume that every number in the matrix is at most 2 digits,
 * and you should use that assumption to align the columns nicely.
 */
void printMatrix(matrix_t* m) {
    // TODO
}

/* ******************* main ***************** */
int main() {
    int n_rows = 3;
    int n_cols = 4;
    int row1[] = { 1, 2, 3, 4 };
    int row2[] = { 5, 6, 7, 8 };
    int row3[] = { 9, 10, 11, 12};
    int* nums[] = { row1, row2, row3 };

    matrix_t matrix = { .nums = nums, .n_rows = n_rows, .n_cols = n_cols };
    printMatrix(&matrix);

    int* diag = (int*)malloc(3 * sizeof(int));
    diagonal(&matrix, diag);
    
    // TODO: Print the diagonal stored in diag

    free(diag);

    matrix_t* matrices = (matrix_t*)malloc(2 * sizeof(matrix_t));
    printf("%p\n", (void*)matrices);
    printf("%p\n", (void*)++matrices);

    return 0;
}
