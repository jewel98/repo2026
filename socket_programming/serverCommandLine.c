int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    char *end;
    long port_value = strtol(argv[1], &end, 10);

    if (*end != '\0' || port_value < 1 || port_value > 65535) {
        fprintf(stderr, "Invalid port: %s\n", argv[1]);
        return 1;
    }

    int port = (int)port_value;

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket,
             (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %d\n", port);

    listen(server_socket, 5);

    /* accept(), read(), write(), etc. */

    close(server_socket);
    return 0;
}
