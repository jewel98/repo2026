#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define PORT 8080

int main(int argc, char const *argv[]){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    //1. Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd<0)  {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    //printf("Socket created successfully\n");

    //2.Binding
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }
    printf("Binding successful\n");   

    //3.Listen
    if (listen(server_fd, 5)<0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }
    printf("Listening for connections...\n");

    //4.Accept
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
     if(new_socket<0){
        perror("Error accepting");
        exit(EXIT_FAILURE);
    } 
    printf("Connection accepted\n");
    //5.read and write
    int valread = read(new_socket, buffer, sizeof(buffer));
    if (valread < 0) {
        perror("read");
    } else {
        printf("Received from client: %s\n", buffer);
    }
    send(new_socket, buffer, strlen(buffer), 0);
    printf("Response sent to client.\n");

    // 6. Close the sockets
    close(new_socket);
    close(server_fd);




    return 0;
}
