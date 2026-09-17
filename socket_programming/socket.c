#include <stdio.h>      // For printf and perror
#include <stdlib.h>     // For exit and EXIT_FAILURE
#include <string.h>     // For memset
#include <unistd.h>     // For close
#include <sys/types.h>  // For data types
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <arpa/inet.h>  // For inet_addr

int main() {
    // Create a socket
    // AF_INET: IPv4 protocol
    // SOCK_STREAM: TCP (reliable, connection-oriented)
    // 0: Let the system choose the appropriate protocol (TCP in this case)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully! File descriptor: %d\n", sockfd);

    // Optionally, you might bind the socket, listen for connections (if a server), or connect (if a client)
    // For now, we'll just close the socket to clean up.
    close(sockfd);

    return 0;
}
