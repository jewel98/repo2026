#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-IP> <port>\n", argv[0]);
        fprintf(stderr, "Example: %s 0.0.0.0 5000\n", argv[0]);
        return 1;
    }

    const char *server_ip = argv[1];

    char *end;
    long port_value = strtol(argv[2], &end, 10);

    if (*end != '\0' || port_value < 1 || port_value > 65535) {
        fprintf(stderr, "Invalid port: %s\n", argv[2]);
        return 1;
    }

    int port = (int)port_value;

    /* 1. Create TCP socket */
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    /* Allow the port to be reused quickly */
    int option = 1;
    setsockopt(
        server_socket,
        SOL_SOCKET,
        SO_REUSEADDR,
        &option,
        sizeof(option)
    );

    /* 2. Prepare server address */
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(
            AF_INET,
            server_ip,
            &server_address.sin_addr
        ) != 1) {
        fprintf(stderr, "Invalid IPv4 address: %s\n", server_ip);
        close(server_socket);
        return 1;
    }

    /* 3. Bind socket to IP address and port */
    if (bind(
            server_socket,
            (struct sockaddr *)&server_address,
            sizeof(server_address)
        ) < 0) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    /* 4. Listen for clients */
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    printf("Server listening on %s:%d\n", server_ip, port);
    printf("Waiting for a client...\n");

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

    inet_ntop(
        AF_INET,
        &client_address.sin_addr,
        client_ip,
        sizeof(client_ip)
    );

    printf(
        "Client connected from %s:%d\n",
        client_ip,
        ntohs(client_address.sin_port)
    );

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
        const char *response =
            "Hello from the server! Message received.";

        send(
            client_socket,
            response,
            strlen(response),
            0
        );
    }

    /* 8. Close sockets */
    close(client_socket);
    close(server_socket);

    return 0;
}
