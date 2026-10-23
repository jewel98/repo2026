#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    socklen_t server_len = sizeof(server_addr);
    ssize_t send_len, recv_len;

    // 1. Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("UDP socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup the server address structure (here using localhost)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    server_addr.sin_port = htons(PORT);

    // 2. Send a message to the server
    const char *message = "Hello UDP Server";
    send_len = sendto(sockfd, message, strlen(message), 0,
                      (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (send_len < 0) {
        perror("sendto failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server: %s\n", message);

    
    // 3. Receive reply from the server
    recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                        (struct sockaddr *)&server_addr, &server_len);
    if (recv_len < 0) {
        perror("recvfrom failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    buffer[recv_len] = '\0';  // Null-terminate the reply
    printf("Received reply from server: %s\n", buffer);

    // 4. Close the socket
    close(sockfd);
    return 0;
}
