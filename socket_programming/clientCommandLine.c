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
        fprintf(
            stderr,
            "Example: %s 192.168.10.223 5000\n",
            argv[0]
        );
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
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        perror("socket");
        return 1;
    }

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
        close(client_socket);
        return 1;
    }

    /* 3. Connect to server */
    if (connect(
            client_socket,
            (struct sockaddr *)&server_address,
            sizeof(server_address)
        ) < 0) {
        perror("connect");
        close(client_socket);
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, port);

    /* 4. Read a message from the keyboard */
    char message[BUFFER_SIZE];

    printf("Enter a message: ");

    if (fgets(message, sizeof(message), stdin) == NULL) {
        fprintf(stderr, "Failed to read message.\n");
        close(client_socket);
        return 1;
    }

    /* Remove the newline added by fgets() */
    message[strcspn(message, "\n")] = '\0';

    /* 5. Send the message */
    if (send(
            client_socket,
            message,
            strlen(message),
            0
        ) < 0) {
        perror("send");
        close(client_socket);
        return 1;
    }

    /* 6. Receive the server's response */
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
        printf("Server closed the connection.\n");
    } else {
        buffer[bytes_received] = '\0';
        printf("Server response: %s\n", buffer);
    }

    /* 7. Close the socket */
    close(client_socket);

    return 0;
}
