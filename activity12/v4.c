#include <stdio.h>
#include <stdlib.h>

struct numbers {
    int n;
    int *nums;
};

struct numbers *numbers;

void create_numbers(struct numbers **nrs, int *n) {
    *n = 3;
    *nrs = malloc(sizeof(struct numbers) * 3);
    
    if (*nrs == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
  
    for (int i = 0; i < 3; i++) {
        (*nrs)[i].n = i + 1;
        (*nrs)[i].nums = malloc(sizeof(int) * (i + 1));
        
        if ((*nrs)[i].nums == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < i + 1; j++) {
            (*nrs)[i].nums[j] = i + j;
        }
    }
}

void output_report(struct numbers *nrs, int index) { 
    printf("Number: %d\n", nrs[index].n);
    for (int i = 0; i < nrs[index].n; i++)
        printf("Value: %d\n", nrs[index].nums[i]);
    printf("\n");
}

int main(int argc, char **argv) {
    int n;
    create_numbers(&numbers, &n);

    for (int i = 0; i < n; i++) {
        output_report(numbers, i);
    }

    numbers = NULL;
    
    for (int i = 0; i < n; ++i) {
        free(numbers[i].nums);
    }
    free(numbers);

    return 0;
}

