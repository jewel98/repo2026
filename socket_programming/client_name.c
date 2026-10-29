#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(
            stderr,
            "Usage: %s <server-IP-or-name> <port>\n",
            argv[0]
        );

        return 1;
    }

    const char *server_name = argv[1];
    const char *port = argv[2];

    /* Check the port */
    char *end;
    long port_value = strtol(port, &end, 10);

    if (port[0] == '\0' ||
        *end != '\0' ||
        port_value < 1 ||
        port_value > 65535) {

        fprintf(stderr, "Invalid port: %s\n", port);
        return 1;
    }

    /*
     * Resolve the server name or IP address.
     *
     * Examples:
     *     localhost
     *     127.0.0.1
     *     192.168.10.223
     *     server-name
     */
    struct addrinfo hints;
    struct addrinfo *address_list;
    struct addrinfo *address;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;       /* IPv4 */
    hints.ai_socktype = SOCK_STREAM; /* TCP */

    int result = getaddrinfo(
        server_name,
        port,
        &hints,
        &address_list
    );

    if (result != 0) {
        fprintf(
            stderr,
            "Cannot resolve %s: %s\n",
            server_name,
            gai_strerror(result)
        );

        return 1;
    }

    /*
     * Try each returned address until one connection succeeds.
     */
    int client_socket = -1;

    for (address = address_list;
         address != NULL;
         address = address->ai_next) {

        client_socket = socket(
            address->ai_family,
            address->ai_socktype,
            address->ai_protocol
        );

        if (client_socket < 0) {
            continue;
        }

        if (connect(client_socket,
                    address->ai_addr,
                    address->ai_addrlen) == 0) {
            break;
        }

        close(client_socket);
        client_socket = -1;
    }

    freeaddrinfo(address_list);

    if (client_socket < 0) {
        fprintf(
            stderr,
            "Could not connect to %s:%s\n",
            server_name,
            port
        );

        return 1;
    }

    printf("Connected to %s:%s\n", server_name, port);

    /* Read a message from the keyboard */
    char message[BUFFER_SIZE];

    printf("Enter a message: ");

    if (fgets(message, sizeof(message), stdin) == NULL) {
        fprintf(stderr, "Failed to read the message.\n");
        close(client_socket);
        return 1;
    }

    /* Remove the newline added by fgets() */
    message[strcspn(message, "\n")] = '\0';

    if (message[0] == '\0') {
        fprintf(stderr, "The message cannot be empty.\n");
        close(client_socket);
        return 1;
    }

    /* Send the message */
    if (send(client_socket,
             message,
             strlen(message),
             0) < 0) {
        perror("send");
        close(client_socket);
        return 1;
    }

    /* Receive the server response */
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

    close(client_socket);

    return 0;
}
