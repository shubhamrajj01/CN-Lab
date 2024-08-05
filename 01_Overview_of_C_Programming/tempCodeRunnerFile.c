#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int number;
    struct pkt packet;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0 || number > 9999) {
        printf("Number out of range\n");
        return 1;
    }

    
    packet.ch1 = (number / 1000) % 10; 
    packet.ch2[0] = (number / 100) % 10; 
    packet.ch2[1] = (number / 10) % 10; 
    packet.ch3 = number % 10; 

    printf("Contents of the structure:\n");
    printf("ch1: %d\n", packet.ch1);
    printf("ch2[0]: %d\n", packet.ch2[0]);
    printf("ch2[1]: %d\n", packet.ch2[1]);
    printf("ch3: %d\n", packet.ch3);

   
    int regenerated_number = (packet.ch1 * 1000) + (packet.ch2[0] * 100) + (packet.ch2[1] * 10) + packet.ch3;
    printf("Regenerated number: %d\n", regenerated_number);

    return 0;
}