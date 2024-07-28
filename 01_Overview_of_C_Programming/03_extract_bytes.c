/*
3. Write a C program to extract each byte from a given number and store them in  
separate character variables and print the content of those variables.
*/

#include <stdio.h>

int main() {
    unsigned int num;
    unsigned char byte1, byte2, byte3, byte4;

    printf("Enter a number: ");
    scanf("%u", &num);

    byte1 = (num & 0xFF);
    byte2 = (num >> 8) & 0xFF;
    byte3 = (num >> 16) & 0xFF;
    byte4 = (num >> 24) & 0xFF;

    printf("Byte 1: %u\n", byte1);
    printf("Byte 2: %u\n", byte2);
    printf("Byte 3: %u\n", byte3);
    printf("Byte 4: %u\n", byte4);

    return 0;
}
