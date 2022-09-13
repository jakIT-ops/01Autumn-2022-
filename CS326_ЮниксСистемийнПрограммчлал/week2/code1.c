#include <fcntl.h>
#include <unistd.h>

void main() {
	int fd;
	fd = open("erdene.bat", O_WRONLY | O_CREAT, 0644);
	write(fd, "Unix Systemiin programchlal", 27);
	close(fd);
}
