
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[1024];
    int bytesReceived;

    // Step 1: Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Step 2: Configure server address
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Step 3: Bind socket
    if (bind(serverSocket,
             (struct sockaddr*)&serverAddress,
             sizeof(serverAddress)) < 0) {
        perror("Bind failed");
        close(serverSocket);
        return 1;
    }

    // Step 4: Listen for connections
    if (listen(serverSocket, 5) < 0) {
        perror("Listen failed");
        close(serverSocket);
        return 1;
    }

    printf("Server waiting on port 5000...\n");

    // Step 5: Accept a client
    clientSocket = accept(serverSocket, NULL, NULL);

    if (clientSocket < 0) {
        perror("Accept failed");
        close(serverSocket);
        return 1;
    }

    printf("Client connected!\n");

    // Step 6: Receive message
    bytesReceived = recv(clientSocket, buffer,
                         sizeof(buffer) - 1, 0);

    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        printf("Client says: %s\n", buffer);

        // Step 7: Send response
        char response[] = "Hello from server!";
        send(clientSocket, response,
             strlen(response), 0);
    }

    // Step 8: Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
