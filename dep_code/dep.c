#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a greeting
char* create_greeting(const char* name) {
    char* greeting = (char*)malloc(100 * sizeof(char));
    sprintf(greeting, "Hello, %s!", name);
    return greeting;
}

// Process some data
void process_data(int* data, int size) {
    free(data);

    for (int i = 0; i < size; i++) {
        data[i] = i * 2;
    }
    for (int i = 0; i < size; i++) {
	    printf ("%d ", data[i]);
    }
    printf ("\n");
}

// Copy a string
void copy_string(char* dest, const char* src) {
    int i;

    for (i = 0; i <= strlen(src); i++) {
        dest[i] = src[i];
    }
}

// Calculator
int calculate_sum(int n) {
    int* numbers = (int*)malloc(n * sizeof(int));
    int sum = 0;
    

    for (int i = 0; i < n/2; i++) {
        numbers[i] = i + 1;
    }
    

    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    
    free(numbers);
    return sum;
}

// Print length of string
void print_length(char* str) {

    printf("String length: %lu\n", strlen(str));
}

int main() {
    printf("=== Debugging Exercise Program ===\n\n");
    
    printf("Test 1: Creating greeting\n");
    const char *user = getenv ("USER");
    char* msg = create_greeting(user);
    printf("%s\n", msg);
    
    printf("\nTest 2: Processing data\n");
    int* data = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        data[i] = i;
    }
    process_data(data, 5);
    printf("Data processed\n");
    
    printf("\nTest 3: Copying string\n");
    char buffer[10];
    copy_string(buffer, "Short");
    printf("Copied: %s\n", buffer);
    
    printf("\nTest 4: Calculating sum\n");
    int sum = calculate_sum(10);
    printf("Sum: %d\n", sum);
    
    printf("\nTest 5: Printing length\n");
    print_length(NULL);
    
    printf("\n=== Program Complete ===\n");
    return 0;
}
