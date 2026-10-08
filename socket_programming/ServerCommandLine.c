#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-IP> <port>\n", argv[0]);
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

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip,
                  &server_address.sin_addr) != 1) {
        fprintf(stderr, "Invalid IPv4 address: %s\n", server_ip);
        close(client_socket);
        return 1;
    }

    if (connect(client_socket,
                (struct sockaddr *)&server_address,
                sizeof(server_address)) < 0) {
        perror("connect");
        close(client_socket);
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, port);

    close(client_socket);
    return 0;
}
