#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>  // Use winsock2.h for Windows

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Receiver IP Address> <Receiver Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];
    port = atoi(argv[2]);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code : %d\n", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code : %d\n", WSAGetLastError());
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip);

    while (1) {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

        sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        int len = sizeof(servaddr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';

        printf("Receiver: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Receiver exited. Exiting...\n");
            break;
        }
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
