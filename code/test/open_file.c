#include "csapp.h"

int main(){
    int fd1,fd2;
    fd1 = open("foo.txt",O_RDONLY);
    Close(fd1);
    fd2 = open("bar.txt",O_RDONLY);
    printf("fd2 = %d\n",fd2);
    exit(0);
}