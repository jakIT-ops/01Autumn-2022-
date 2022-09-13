#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd;
	if (open("text.txt", O_WRONLY, 0644) < 0) {
		printf("Aldaanii dugaar %d\n", errno);
		perror("File neej chadsanggv");
		exit(1);
	}

	write(fd, "Unix Systemiin programchilal", 27);
	close(fd);

	/*Aldaaniii bolowsruulalt
	 *
	 * Ihewchlen systemiin duudaltuud ni aldaa garwal -1 gesen utha butsaadag.
	 *
	 * if (fd < 0)
	 * harin aldaanii delgrengvi medeelling kernal ni errno gedeg global huwisagchid onoochihdog
	 *
	 * Errno = 2
	 *  * no such file or dir found
	 *
	 * Errno = 13
	 *
	 *  * Permission denied
	 *
	 * Errno ni haana todorhoilogdson be
	 *
	 *  # include <errno.h>
	 *
	 * */

	return 0;
}
