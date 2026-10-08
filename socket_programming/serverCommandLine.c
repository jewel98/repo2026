// server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // The server requires only the port number.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    char *end;
    long port = strtol(argv[1], &end, 10);

    if (*end != '\0' || port < 1 || port > 65535) {
        fprintf(stderr, "Invalid port: %s\n", argv[1]);
        return 1;
    }

    // Create a TCP socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    // Allow quick reuse of the port.
    int option = 1;

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR,
                   &option, sizeof(option)) < 0) {
        perror("setsockopt");
        close(server_socket);
        return 1;
    }

    // Configure the server address.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons((int)port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the port.
    if (bind(server_socket,
             (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections.
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    printf("Server is listening on port %ld...\n", port);

    // Accept one client.
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

    inet_ntop(
        AF_INET,
        &client_address.sin_addr,
        client_ip,
        sizeof(client_ip)
    );

    printf("Client connected from %s:%d\n",
           client_ip,
           ntohs(client_address.sin_port));

    // Receive a message.
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
        printf("Client disconnected.\n");
    } else {
        buffer[bytes_received] = '\0';
        printf("Client message: %s\n", buffer);

        // Send a response.
        const char *response =
            "Hello from the server!";

        if (send(client_socket,
                 response,
                 strlen(response),
                 0) < 0) {
            perror("send");
        }
    }

    close(client_socket);
    close(server_socket);

    return 0;
}
