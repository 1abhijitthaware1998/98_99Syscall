#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{ 
    int fd;

    fd=open("DAC.txt",O_CREAT|O_WRONLY);
    if(fd==-1)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
   write(fd,"Hello",5);
   close(fd);
   return 0;
}