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
#include <pthread.h> //for POSIX threads, link with lpthread 
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
	n = write(sock, "I got your message", 18);
	if (n < 0) error("ERROR writing to socket");
	if (close(sock) == -1) error("Error closing socket used by thread");
	return;
}

// Structure of arguments to pass to client thread 
struct threadArgs {
	int clntSock;
};
void threadMain(void* arg)
{
	int cSock; // Socket descriptor for client connection 
	pthread_detach(pthread_self());
	// Guarantees that thread resources are deallocated upon return 
	// Extract socket file descriptor from argument 
	cSock = ((struct threadArgs*)arg)->clntSock;
	free(arg); // Deallocate memory for argument 
	HandleTCPClient(cSock);
	return (NULL);
}

int main(int argc, char* argv[])
{
	int servSock; // Socket descriptor for server 
	int comSock; // Socket descriptor for client communication 
	int portno; // Server port 
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;
	pthread_t threadID; // Thread ID from pthread_create()
	struct threadArgs* tArgs; // Pointer to argument structure for thread 
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
	*process will go in sleep modeand will wait
		* for the incoming connection
		listen(servSock, 5);
	clilen = sizeof(cli_addr);

	for (;;) { // Run forever 
		comSock = accept(servSock, (struct sockaddr*)&cli_addr, &clilen);
		if (comSock == -1)error("ERROR on accept");
		// Create separate memory for client argument 
		//if ((tArgs = (struct threadArgs*)malloc(sizeof(struct threadArgs))) == NULL)
			//error("Cannot allocate memory for thread arguments");
		//tArgs->clntSock = comSock;
		// Create client thread 
		//if (pthread_create(&threadID, NULL, threadMain, (void*)tArgs) != 0)
			//error("Cannot create thread to handle client");
	}
	// NOT REACHED 
}

