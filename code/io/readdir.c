#include "csapp.h"

int main(int argc, char **argv){
    DIR *streamp;
    struct drient *dep;
    streamp = Opendir(argv[1]);
    errno = 0;
    while ((dep = readdir(streamp)) != NULL) { 
        printf("%s\n", dep->d_name);
    }
    if (errno!=0) unix_error(errno);
    CloseDir(streamp);
    exit(0);
    
}