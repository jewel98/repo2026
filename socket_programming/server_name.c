//Server requires only the port.
//Client accepts either an IPv4 address or a hostname.
//./server 5000
//./client localhost 5000 or ./client 127.0.0.1 5000
//./client 192.168.10.223 5000 or ./client server-name 5000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    char *end;
    long port = strtol(argv[1], &end, 10);

    if (argv[1][0] == '\0' ||
        *end != '\0' ||
        port < 1 ||
        port > 65535) {

        fprintf(stderr, "Invalid port: %s\n", argv[1]);
        return 1;
    }

    /* 1. Create a TCP socket */
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    /* Allow the port to be reused */
    int option = 1;

    if (setsockopt(server_socket,
                   SOL_SOCKET,
                   SO_REUSEADDR,
                   &option,
                   sizeof(option)) < 0) {
        perror("setsockopt");
        close(server_socket);
        return 1;
    }

    /* 2. Configure the server address */
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons((unsigned short)port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 3. Bind the socket */
    if (bind(server_socket,
             (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    /* 4. Listen for connections */
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %ld...\n", port);

    /* 5. Accept one client */
    struct sockaddr_in client_address;
    socklen_t client_length = sizeof(client_address);

    int client_socket = accept(
        server_socket,
        (struct sockaddr *)&client_address,
        &client_length
    );

    if (client_socket < 0) {
        perror("accept");
        close(server_socket);
        return 1;
    }

    char client_ip[INET_ADDRSTRLEN];

    if (inet_ntop(AF_INET,
                  &client_address.sin_addr,
                  client_ip,
                  sizeof(client_ip)) == NULL) {
        strcpy(client_ip, "unknown");
    }

    printf("Client connected from %s:%d\n",
           client_ip,
           ntohs(client_address.sin_port));

    /* 6. Receive a message */
    char buffer[BUFFER_SIZE];

    ssize_t bytes_received = recv(
        client_socket,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytes_received < 0) {
        perror("recv");
    } else if (bytes_received == 0) {
        printf("Client disconnected without sending data.\n");
    } else {
        buffer[bytes_received] = '\0';

        printf("Client message: %s\n", buffer);

        /* 7. Send a response */
        const char *response = "Message received by the server.";

        if (send(client_socket,
                 response,
                 strlen(response),
                 0) < 0) {
            perror("send");
        }
    }

    /* 8. Close the sockets */
    close(client_socket);
    close(server_socket);

    return 0;
}
