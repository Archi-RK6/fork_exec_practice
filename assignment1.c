#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int ret = fork();

    if(ret == 0){
        execl("/bin/ls", "ls", NULL);
        perror("execl");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }
    return 0;
}