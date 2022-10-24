/*
 * *mmap()
 * - file - iig sanah oi ruu buulgana
 * - tuhain file ruugaa massiv ruu handaj baigaa ym shig handah bolomj olgono.
 * */
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

struct record {
	int id;
	char name[80];
};

int main() {
	int fd;
	size_t size;
	sturct record *records;

	fd = open("foo", O_RDWR);
	size = lseek(fd, 0, SEEK_END);
				// mmap(addr, length, prot, flags, fd, offset)
records = (struct record *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE,fd, 0);

	records[1].id = 99;
	msync(records, size, MS_SYNC);
}

/*
 *Sanah oi ruu buulgaad, tvvndee ogogdloo oorchlood sink hiine. File ruu shuurhai handah goymsog arga ym.
 * */



