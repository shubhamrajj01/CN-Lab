/*
5. Write a C program to check whether the Host machine is in Little Endian or  
Big Endian. Enter a number, print the content of each byte location and  
Convert the Endianness of the same i.e. Little to Big Endian and vice-versa
*/

#include <stdio.h>
#include <stdint.h>

void checkEndianness() {
    unsigned int x = 1;
    char *c = (char*)&x;
    if (*c)
        printf("The system is Little Endian\n");
    else
        printf("The system is Big Endian\n");
}

void printBytes(uint64_t num) {
    unsigned char *ptr = (unsigned char*)&num;
    printf("Byte representation: ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02x ", *(ptr + i));
    }
    printf("\n");
}

uint64_t convertEndianness(uint64_t num) {
    uint64_t byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7;
    byte0 = (num & 0x00000000000000FF) >> 0;
    byte1 = (num & 0x000000000000FF00) >> 8;
    byte2 = (num & 0x0000000000FF0000) >> 16;
    byte3 = (num & 0x00000000FF000000) >> 24;
    byte4 = (num & 0x000000FF00000000) >> 32;
    byte5 = (num & 0x0000FF0000000000) >> 40;
    byte6 = (num & 0x00FF000000000000) >> 48;
    byte7 = (num & 0xFF00000000000000) >> 56;
    return (byte0 << 56) | (byte1 << 48) | (byte2 << 40) | (byte3 << 32) | 
           (byte4 << 24) | (byte5 << 16) | (byte6 << 8) | (byte7 << 0);
}

int main() {
    uint64_t num, convertedNum;

    checkEndianness();

    printf("Enter a number: ");
    scanf("%lu", &num);

    printf("Original number in bytes:\n");
    printBytes(num);

    convertedNum = convertEndianness(num);

    printf("Converted number in bytes:\n");
    printBytes(convertedNum);

    printf("Original number: %lu\n", num);
    printf("Converted number: %lu\n", convertedNum);

    return 0;
}
