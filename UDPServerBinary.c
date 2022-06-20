/* Program Skeleton 1: A simple UDP server -> Usage: UDPsimpleserver <port> */

#include <stdio.h>
#include <string.h> // Necessary for memset() 
#include <stdlib.h> // Necessary for exit() 

#include <unistd.h> /* contains various constants */

#include <netdb.h> /* This is needed in UDP servers too */
#include <sys/types.h> //define some data types used in system calls 
#include <sys/socket.h> //definitions of structures needed for sockets 

#include <netinet/in.h>
/*constants and structures needed for internet domain addresses */

#include <arpa/inet.h>  /* It is needed because inet_ntoa() */

#define BUFSIZE 1024


/* error - wrapper for perror */
void error(char* msg) {
    perror(msg);
    exit(0);
}
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

int main(int argc, char* argv[]) {
    int sockid; /* socket */
    int portno; /* port to listen on */
    int clientlen; /* byte size of client's address */
    struct sockaddr_in serveraddr; /* server's addr */
    struct sockaddr_in clientaddr; /* client addr */
    struct hostent* hostp; /* client host info */
    char buf[BUFSIZE]; /* message buf */
    char* hostaddrp; /* dotted decimal host addr string */
    int optval; /* flag value for setsockopt  */
    int n; /* message byte size */
    /*  check command line arguments  */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[1]);/*Takes argument in cmd line for the port as interger */
    /* socket: create the advertising socket */
    sockid = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockid < 0)
        error("ERROR opening socket");
    /* setsockopt: * Handy debug trick that lets rerun the server
     *immediately after being killed;
     * otherwise one needs to wait about 20 secs.
     * Eliminates "ERROR on binding: Address already in use" error.
     */
    optval = 1;
    setsockopt(sockid, SOL_SOCKET, SO_REUSEADDR,
        (const void*)&optval, sizeof(int));

    // build the server's Internet address 
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;//htonl(INADDR_ANY);
    serveraddr.sin_port = htons(portno);

    //  bind: associate the advertising socket with a port  
    if (bind(sockid, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
        error("ERROR on binding");

    // main loop: wait for a datagram, then echo it 
    clientlen = sizeof(clientaddr);
    while (1) {
        // recvfrom: receive a UDP datagram from a client 
        memset(buf, 0, BUFSIZE);
        n = recvfrom(sockid, (char*)buf, BUFSIZE, 0,
            (struct sockaddr*)&clientaddr, &clientlen);
        if (n < 0)
            error("ERROR in recvfrom");
        // gethostbyaddr: determine who sent the datagram
        hostp = gethostbyaddr((const char*)&clientaddr.sin_addr.s_addr,
            sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        if (hostp == NULL)
            error("ERROR on gethostbyaddr");
        hostaddrp = inet_ntoa(clientaddr.sin_addr);
        if (hostaddrp == NULL)
            error("ERROR on inet_ntoa\n");
        printf("server received datagram from %s (%s)\n",
            hostp->h_name, hostaddrp);
        printf("server received %lu/%d bytes: %s\n", strlen(buf), n, buf);


        long int myBinaryNum = 0;
        for (int i = 0;i < BUFSIZE;i++) {
            if (buf[i] == '1') {
                myBinaryNum = myBinaryNum * 10 + 1;
            }
            else if (buf[i] == '0') {
                myBinaryNum = myBinaryNum * 10;
            }
            buf[i] = 0;
        }
        int tempInt = covertBinToDec(myBinaryNum);
        snprintf(buf, 10, "%d", tempInt);


        // sendto: echo the input back to the client  
        n = sendto(sockid, buf, strlen(buf), 0,
            (struct sockaddr*)&clientaddr, clientlen);
        if (n < 0)
            error("ERROR in sendto");
    }
}