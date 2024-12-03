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
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};
    ssize_t read_bytes;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    const char *message = "Hello from the client!";
    if (write(sock_fd, message, strlen(message)) == -1) {
        perror("write failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    read_bytes = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (read_bytes < 0) {
        perror("read failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    buffer[read_bytes] = '\0'; 
    printf("Received from server: %s\n", buffer);

    close(sock_fd);

    return 0;
}


