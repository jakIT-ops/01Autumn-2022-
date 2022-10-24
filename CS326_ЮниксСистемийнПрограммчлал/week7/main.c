#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[]){
	struct stat sb; // the stat buffer 
	// Array of file types, indexed by the top four bitd of st_mode
	char *filetype[] = {
		"unknown", "FIFO", "character device", "unknown", "directory",
		"unknown", "block device", "unknown", "file",
		"unknown", "symlink", "unknown", "socket" };

	if(argc != 2) {
		fprintf(stderr, "usage: listfile filename\n");
		exit(1);
	}

	if (stat(argv[1], &sb) < 0) {
		perror(argv[1]);
		exit(2);
	}


}

