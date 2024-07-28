/*
1. Write a C program to swap the content of 2 variables entered through the command line using function and pointer. 
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Original values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    swap(&num1, &num2);

    printf("Swapped values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}
