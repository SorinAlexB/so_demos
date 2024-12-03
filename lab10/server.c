#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    ssize_t read_bytes;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;            
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);         

    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    client_fd = accept(server_fd, (struct sockaddr *)&address, &addr_len);
    if (client_fd < 0) {
        perror("accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    read_bytes = read(client_fd, buffer, BUFFER_SIZE - 1);
    if (read_bytes < 0) {
        perror("read failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    buffer[read_bytes] = '\0';
    printf("Received from client: %s\n", buffer);

    const char *response = "Hello from the server!";
    if (write(client_fd, response, strlen(response)) == -1) {
        perror("write failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}

