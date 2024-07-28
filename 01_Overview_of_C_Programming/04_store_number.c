/*
4. Write a C Program to enter a number and store the number across the
following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and
print the same.
struct pkt {
char ch1;
char ch2[2];
char ch3;
};
*/

#include <stdio.h>
#include <string.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    int number;
    struct pkt packet;
    char *ptr = (char *)&packet;

    printf("Enter a number: ");
    scanf("%d", &number);

    memcpy(ptr, &number, sizeof(packet));

    printf("Content of ch1: %d\n", packet.ch1);
    printf("Content of ch2[0]: %d\n", packet.ch2[0]);
    printf("Content of ch2[1]: %d\n", packet.ch2[1]);
    printf("Content of ch3: %d\n", packet.ch3);

    int aggregatedNumber = 0;
    memcpy(&aggregatedNumber, ptr, sizeof(packet));

    printf("Aggregated number: %d\n", aggregatedNumber);

    return 0;
}
