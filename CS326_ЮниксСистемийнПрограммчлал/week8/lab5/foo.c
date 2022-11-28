#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int ret;
	ret = mkdir("mynewdir", S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH);

//	ret = rmdir("mynewdir");
	
	//ret = symlink("mynewdir", "hellodir");
	
	ret = unlink("hellodir");
	return 0;
}
	

