#include <csapp.h>

int main(int argc, char *argv[], char *envp[]){
    int i;
    printf("Command Line Arguments: \n");
    for (i=0; argv[i] != NULL; i++) printf("argv[%d]: %s \n", i, argv[i]);
    printf("Environment Arguments: \n");
    for (i=0; envp[i] != NULL; i++) printf("envp[%d]: %s \n", i, envp[i]);
}