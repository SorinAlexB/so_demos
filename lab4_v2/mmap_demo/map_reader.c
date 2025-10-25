#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(void) {
    int fd = open("hello.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    struct stat st;
    fstat(fd, &st);
    size_t size = st.st_size;

    char *map = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(1);
    }

    printf("[reader] reading from hello.txt via mmap:\n");
    write(STDOUT_FILENO, map, size);
    printf("\n");

    munmap(map, size);
    close(fd);
    return 0;
}
