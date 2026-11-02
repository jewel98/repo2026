
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[1024];
    int bytesReceived;

    // Step 1: Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Step 2: Configure server address
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);

    inet_pton(AF_INET, "127.0.0.1",
              &serverAddress.sin_addr);

    // Step 3: Connect to server
    if (connect(clientSocket,
                (struct sockaddr*)&serverAddress,
                sizeof(serverAddress)) < 0) {
        perror("Connection failed");
        close(clientSocket);
        return 1;
    }

    printf("Connected to server!\n");

    // Step 4: Send message
    char message[] = "Hello from client!";
    send(clientSocket, message,
         strlen(message), 0);

    // Step 5: Receive response
    bytesReceived = recv(clientSocket, buffer,
                         sizeof(buffer) - 1, 0);

    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        printf("Server says: %s\n", buffer);
    }

    // Step 6: Close socket
    close(clientSocket);

    return 0;
}
