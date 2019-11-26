
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
 
#define BUF_SIZE 20
 
int main() {
 
    int fd1, fd2;    /* Input and output file descriptors */
    ssize_t n1, n2;    /* Number of bytes returned by read() and write() */
    char buffer[BUF_SIZE];      /* Character buffer */
 
    /* Are src and dest file name arguments missing */
  /* if(argc != 3){
      printf ("Usage: cp file1 file2");
        return 1;
    }*/
 
    /* Open input file descriptor */
    fd1 = open ("DAC.txt", O_RDONLY);
    if (fd1 == -1) {
            perror ("1");
            return 2;
    }
 
    /* Create output file descriptor */
    fd2 = open("DESD.txt", O_RDWR | O_CREAT);
    if(fd2 == -1){
        perror("2");
        return 3;
    }
 
    /* Copy process */
    while((n1 = read (fd1, &buffer, BUF_SIZE)) > 0){
            n2 = write (fd2, &buffer, (ssize_t) n1);
            if(n2 != n1){
                /* Write error */
                perror("3");
                return 4;
            }
    }
 
    /* Close file descriptors */
    close (fd1);
    close (fd2);
 
    return (EXIT_SUCCESS);
}
