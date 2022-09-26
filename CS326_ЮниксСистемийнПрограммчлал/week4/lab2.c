#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int const a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int fd = open( "array.txt",
                          O_WRONLY | O_CREAT, S_IWRITE | S_IREAD);
    if(fd==-1) {
        perror("Cannot open file");
        return 1;
    }
    if(write(fd, a, sizeof(a) )<0) {
        perror("Write error");
    }
    close( fd);
//https://dextutor.com/lseek-system-call/
    return 0;
}
/*
// *
//int main( void )
//{
//    int fd;
//    int size_read;
//    char buffer[80];
//
//    /* Open a file for input */
//fd = open( "myfile.dat", O_RDONLY );
//
///* Read the text */
//size_read = read( fd, buffer,
//                  sizeof( buffer ) );
//
///* Test for error */
//if( size_read == -1 ) {
//perror( "Error reading myfile.dat" );
//return EXIT_FAILURE;
//}
//
///* Close the file */
//close( fd );
//
//return EXIT_SUCCESS;
//}
// * */

//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio.h>
//#include <unistd.h>

//int main() {
//
//    int const in { open( "testnums.out", O_RDONLY ) };
//
//    if(in==-1) {
//        perror("Cannot open file");
//        return 1;
//    }
//
//    int a[10];
//    ssize_t const r { read( in, a, sizeof(a) ) };
//    if(r!=sizeof(a)) {
//        fprintf(stderr, "Could not read complete array.");
//        return 1;
//    }
//    if(r<0) {
//        perror("Read error");
//        close(in);
//        return 1;
//    }
//    close(in);
//
//    for(unsigned int i(0); i<sizeof(a)/sizeof(int); ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//
//    return 0;
//}



