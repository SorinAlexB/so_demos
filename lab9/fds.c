#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){


	int fd = open("file.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
	char buf[] = "Hello using fd\n";
	char buf2[] = "Hello using fd2\n";
	char read_buf[strlen(buf)+strlen(buf2)]; 

	write(fd, buf, strlen(buf));
	lseek(fd, 0, SEEK_SET);
	read(fd, read_buf, strlen(buf));
	read_buf[strlen(buf)] = '\0';
	printf("%s", read_buf);

	int fd2 = dup(fd);

	write(fd2, buf2, strlen(buf2));
	lseek(fd, 0, SEEK_SET);
	read(fd, read_buf, strlen(buf)+strlen(buf2));
	read_buf[strlen(buf)+strlen(buf2)] = '\0';
	printf("%s", read_buf);

	close(fd);
	close(fd2);

   	return 0;	
}
