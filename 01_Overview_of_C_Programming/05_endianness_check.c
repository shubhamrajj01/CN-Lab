/*
5. Write a C program to check whether the Host machine is in Little Endian or  
Big Endian. Enter a number, print the content of each byte location and  
Convert the Endianness of the same i.e. Little to Big Endian and vice-versa
*/

#include <stdio.h>

void checkEndian() {
    unsigned int x = 1;
    unsigned char *c = (unsigned char*)&x;
    if (*c) {
        printf("Host machine is Little Endian\n");
    } else {        printf("Host machine is Big Endian\n");
    }
}

void printBytes(unsigned int num) {
    unsigned char *bytePtr = (unsigned char*)&num;
    printf("Byte content: ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02x ", bytePtr[i]);
    }
    printf("\n");
}

unsigned int convertEndian(unsigned int num) {
    unsigned int b0, b1, b2, b3;
    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;
    return (b0 | b1 | b2 | b3);
}

int main() {
    unsigned int number;

    checkEndian();

    printf("Enter a number: ");
    scanf("%u", &number);

   
    printf("Original number: %u\n", number);
    printBytes(number);

    unsigned int convertedNumber = convertEndian(number);


    printf("Converted number: %u\n", convertedNumber);
    printBytes(convertedNumber);

    return 0;
}