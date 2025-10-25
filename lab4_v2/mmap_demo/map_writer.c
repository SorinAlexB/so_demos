#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(void) {
    const char *msg = "hello from file\n";

    int fd = open("hello.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = strlen(msg);

    // Resize file to hold the message
    if (ftruncate(fd, size) < 0) {
        perror("ftruncate");
        close(fd);
        exit(1);
    }

    // Map the file with read/write permissions
    // Try MAP_PRIVATE to see what happens
    char *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(1);
    }

    printf("[writer] writing to hello.txt via mmap\n");

    // Write the message into the mapped memory
    memcpy(map, msg, size);

    printf("[writer] Message written.\n");

    munmap(map, size);
    close(fd);
    return 0;
}
