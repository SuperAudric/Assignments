// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT     8080 
#define MAXLINE 1024 

// Driver code 
int main(int argc, char* argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    if (argc < 2) {
        perror("enter a number to convert from binary next time");
        exit(EXIT_FAILURE);
    }
    char* hello = argv[1];
    struct sockaddr_in     servaddr;

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information 
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    int len, n;
    len = sizeof(servaddr);
    sendto(sockfd, (const char*)hello, strlen(hello),
        0, (const struct sockaddr*)&servaddr,
        sizeof(servaddr));
    printf("Hello message sent.\n");

    n = recvfrom(sockfd, (char*)buffer, MAXLINE,
        0, (struct sockaddr*)&servaddr,
        &len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);

    close(sockfd);
    return 0;
}