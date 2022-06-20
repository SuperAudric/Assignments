#include <stdio.h>
// Headers needed for the socket programming 
#include <sys/types.h> //define some data types used in system calls 
#include <sys/socket.h> //definitions of structures needed for sockets 
#include <netinet/in.h>
//constants and structures needed for internet domain addresses 
#include <errno.h> // Necessary because errno value used 
#include <string.h> // Necessary for memset() 
#include <stdlib.h> // Necessary for exit() 
#include <unistd.h>

#define LIMIT 3

void error(char* msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void HandleTCPClient(int sock)
{
	int n;
	char buffer[256];
	memset(buffer, 0, 256);
	n = read(sock, buffer, 255);
	if (n < 0) error("ERROR reading from socket");
	printf("Here is the message: %s\n", buffer);
	if (strcmp(buffer,"/time")==0)
		n = write(sock, "My time is", 18);
	else
		n = write(sock, "I got your message", 18);
	if (n < 0) error("ERROR writing to socket");
	if (close(sock) == -1) error("Error closing socket used by thread");
	return;
}


int main(int argc, char* argv[])
{
	int servSock; // Socket descriptor for server 
	int comSock; // Socket descriptor for client communication 
	int portno; // Server port 
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

	// Test for correct number of arguments 
	if (argc < 2) error("ERROR: Missing server port argument");
	portno = atoi(argv[1]); // First arg: local port 
	// First call to socket() function 
	servSock = socket(AF_INET, SOCK_STREAM, 0);
	if (servSock == -1) error("ERROR opening server socket");

	// Initialize socket structure 
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(portno);
	// Now bind the host address using bind() call.
	if (bind(servSock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error("ERROR on binding");
	// Now start listening for the clients, here
	// process will go in sleep mode and will wait
	// for the incoming connection 
	listen(servSock, 5);
	clilen = sizeof(cli_addr);

	for (int i = 0;i < LIMIT;i++)// Run LIMIT times 
	{  
		comSock = accept(servSock, (struct sockaddr*)&cli_addr, &clilen);
		if (comSock == -1)error("ERROR on accept");
		HandleTCPClient(comSock);
	}
	// NOT REACHED 
}

