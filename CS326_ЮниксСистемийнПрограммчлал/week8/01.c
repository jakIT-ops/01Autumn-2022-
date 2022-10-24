#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

void main() {
	DIR *d;
	struct dirent *info; /* A directory entry */
	struct stat sb;   // The stat buffer 
	long total = 0; // total of file sizes
	
	d = opendir(".");

	while ((infdo = readdir(d)) != NULL ) {
		stat(info->d_name, &sb);
		total += sb.st_size;
	}

	closedir(d);
	printf("total size = %sld\n", total);
