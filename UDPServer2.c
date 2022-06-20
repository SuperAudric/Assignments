// Server side implementation of UDP client-server model 
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

int power(int i)
{
    int j, p = 1;
    for (j = 1;j <= i;j++)
        p = p * 2;
    return(p);
}

int covertBinToDec(long int n)
{
    int x, s = 0, i = 0, flag = 1;
    while (flag == 1)
    {
        x = n % 10;
        s = s + x * power(i);
        i = i + 1;
        n = n / 10;
        if (n == 0)
            flag = 0;
    }
    return s;
}

// Driver code 
int main() {
    int sockfd;
    char buffer[MAXLINE];
    char* hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information 
    servaddr.sin_family = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address 
    if (bind(sockfd, (const struct sockaddr*)&servaddr,
        sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;

    len = sizeof(cliaddr);  //len is value/result 

    n = recvfrom(sockfd, (char*)buffer, MAXLINE,
        0, (struct sockaddr*)&cliaddr,
        &len);
    buffer[n] = '\0';
    long int myBinaryNum = 0;
    for (int i = 0;i < MAXLINE;i++) {
        if (buffer[i] == '1') {
            myBinaryNum = myBinaryNum * 10 + 1;
        }
        else if(buffer[i] == '0') {
            myBinaryNum = myBinaryNum * 10;
        }
    }
    printf("Client : %s\n", buffer);
    int temp = covertBinToDec(myBinaryNum);
    //if (temp!=NULL){ 
    snprintf(buffer, 10, "%d", temp);
    sendto(sockfd, (const char*)buffer, strlen(buffer),
        0, (const struct sockaddr*)&cliaddr,
        len);
    printf("Hello message sent.\n");

    return 0;
}