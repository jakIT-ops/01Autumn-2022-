#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
//#include    "ourhdr.h"

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int main() {
    int fd; 

    if ((fd = open("file1.txt", O_RDWR, O_CREAT)) < 0)
    	perror("File aldaa");

    if (write(fd, buf1, 10) != 10)
        perror("buf1 write err"); // offset 10

    if (lseek(fd, 40, SEEK_SET) == -1) // offset 40
        perror("lseek error");

    if (write(fd, buf2, 10) != 10)  // offset 50
        perror("buf2 write error");

    return 0;
    exit(0);
}
